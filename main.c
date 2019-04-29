#include "ft_ls.h"

//void		find_flags(int argc, char **argv)
//{

	// int     flags[5] = {0};
    // int	    i = 1;
	// int	    b = 1;

	// while (b < argc)
	// {
	// 	while (argv[b][i])
	// 	{
	// 		if (argv[b][0] == '-' && argv[b][i] != 'l' && argv[b][i] != 'R'
    //                 && argv[b][i] != 'a'
    //                 && argv[b][i] != 'r' && argv[b][i] != 't')
	// 		{
	// 			write(1, "options: lRart\n", 15);
	// 			return ;
	// 		}
	// 		else if (argv[b][0] == '-' && argv[b][i] == 'l')		
	// 			flags[0] = 1;
	// 		else if (argv[b][0] == '-' && argv[b][i] == 'R')		
	// 			flags[1] = 1;
    //         else if (argv[b][0] == '-' && argv[b][i] == 'a')		
	// 			flags[2] = 1;
    //         else if (argv[b][0] == '-' && argv[b][i] == 'r')		
	// 			flags[3] = 1;
    //         else if (argv[b][0] == '-' && argv[b][i] == 't')		
	// 			flags[4] = 1;
	// 		i++;
	// 	}
	// 	b++;
	// 	i = 1;
	// }
	// i = 0;
	// while(i < 5)
	// {
	// 	my_putnbr((size_t)flags[i]);
	// 	i++;
	// }
	// //return (flags);
//}
void	find_flags(char *flags, char *dir)
{
	int i;

	i = 1;
	// while (flags[i])
	// {
		if(flags[i] == 'l')
			l_flag(dir);
	// }
			if(flags[i] == 'R')
			recursive_flag(dir);
}

void	l_flag(char *dir)
{
	DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
	size_t spaces;
	struct passwd *passw;
	struct tm *time;
	struct group *gr;
	size_t size;

    mydir = opendir(dir);
	spaces = find_max(dir, 1);
	size = find_max(dir, 2);
	while((myfile = readdir(mydir)) != NULL)
	{
		stat(myfile->d_name, &mystat);
		passw = getpwuid(mystat.st_uid);
		gr = getgrgid(mystat.st_gid);
		print_permissions(mystat.st_mode, (size_t)myfile->d_type);
		space_count((size_t)mystat.st_nlink, spaces);
		ft_putendl(passw->pw_name);
		write(1, "  ", 2);
		ft_putendl(gr->gr_name);
		write(1, "  ", 2);
		space_count((size_t)mystat.st_size, size);
		time = localtime(&mystat.st_mtimespec.tv_sec);
		print_time(asctime(time));
		ft_putendl(myfile->d_name);
		write(1, "\n", 1);
	}
	closedir(mydir);
}

void	no_flags(char *dir)
{
	DIR *mydir;
	struct dirent *myfile;

	mydir = opendir(dir);
	while((myfile = readdir(mydir)) != NULL)
	{
		ft_putendl(myfile->d_name);
		write(1, "  ", 2);
	}
	closedir(mydir);
}

int main(int argc, char* argv[])
{
	DEBprog()
	int i;
	// if (argc == 2)
	// 	find_flags(argv[3], ".");
	// else
	// 	find_flags(argv[1], argv[2]);

	i = 1;
	if (argc == 1)
	{
		no_flags((char *)("."));
		return(0);
	}
	cr_lists(argv[1]);
	// if (argv[1][0] != '-' && argc > 2)
	// {
	// 	while(argv[i])
	// 	{
	// 		ft_putendl(argv[i]);
	// 		write(1, ":\n", 2);
	// 		no_flags(argv[i]);
	// 		i++;
	// 	}
	// 	return (0);
	// }
	// if (argv[1][0] == '-')
	// {
	// 	//find_flags(argc, argv);
	// 	find_flags(argv[1], argv[2]);
	// 	return (0);
	// }
	// else
	// 	no_flags(argv[1]);
	return (0);
}