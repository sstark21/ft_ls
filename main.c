#include "ft_ls.h"

/*

int	main(int ac, char **av)
{
	DIR *dir;
	struct dirent *sd;
	struct stat *mystat;
	char buf[512];

	dir = opendir(".");
	if (dir == NULL)
	{
		printf("Error! Unable to open directory.\n");
		exit (1);
	}
	while ((sd=readdir(dir)) != NULL)
		stat(dir->d_name, &mystat);
		printf("%s  ", sd->d_name);
		printf("%lld", mystat->st_size); 
	write (1, "\n", 1);
	
	//
	//sprintf(buf, "%s", ".", sd->d_name);
	//stat(buf, &mystat);
	closedir(dir);
	return (0);
}
*/

void	find_flags(char *flags, char *dir)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if(flags[i] == '-')
			i++;
		else 
		{
			write(1, "ERROR", 6);
			exit(0);
		}
		if(flags[i] == 'l')
			l_flag(dir);
	}
}

void	l_flag(char *dir)
{
	DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
	size_t spaces;
	struct passwd *passw;
	struct tm *time;

    mydir = opendir(dir);
	spaces = find_max(dir, 1);
	while((myfile = readdir(mydir)) != NULL)
	{
		stat(myfile->d_name, &mystat);
		passw = getpwuid(mystat.st_uid);
		print_permissions(mystat.st_mode, (size_t)myfile->d_type);
		link_count((size_t)mystat.st_nlink, spaces);
		ft_putendl(passw->pw_name);
		write(1, "\n", 1);
	}
}

int main(int argc, char* argv[])
{
	if (argc == 2)
		find_flags(argv[1], ".");
	else
		find_flags(argv[1], argv[2]);	

    // DIR *mydir;
    // struct dirent *myfile;
    // struct stat mystat;

    // mydir = opendir(argv[2]);
	// if (argc == 2)
	// 	mydir = opendir(".");
    // while((myfile = readdir(mydir)) != NULL)
    // {
	
    //     stat(myfile->d_name, &mystat);    
    //     //printf("%lld",mystat.st_size);
    //     //fake_printf_la("%p  %l   %s %n   ", mystat.st_mode, myfile->d_type, mystat.st_nlink, mystat.st_size, myfile->d_name);
	// 	//fake_printf_la("%s", myfile->d_type);
	// 	//printf("%c\n", myfile->d_type);
	// 	//my_putnbr(mystat.st_nlink);
	// 	print_permissions(mydir);
	// 	//link_count(mydir);
	// 	write(1, "\n", 1);
	// 	//printf("%lld", mystat->st_size);
    // }
	// //printf("%lu\n%lu\n%lu\n", sizeof(int), sizeof(unsigned short), sizeof(unsigned short*));
	// //printf("%lu\n", sizeof(mystat.st_rdev));
	// //printf("%lu\n", sizeof(mode_t));
    // closedir(mydir);
}