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

int main(int argc, char* argv[])
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    mydir = opendir(argv[1]);
	if (argc == 1)
		mydir = opendir(".");
    while((myfile = readdir(mydir)) != NULL)
    {
	
        stat(myfile->d_name, &mystat);    
        //printf("%lld",mystat.st_size);
        fake_printf_la("%p  %s %n ", mystat.st_mode, myfile->d_type, mystat.st_size, myfile->d_name);
		//fake_printf_la("%s", myfile->d_type);
		//printf("%c\n", myfile->d_type);
		//my_putnbr(mystat.st_nlink);
		write(1, "\n", 1);
		//printf("%lld", mystat->st_size);
    }
	//printf("%lu\n%lu\n%lu\n", sizeof(int), sizeof(unsigned short), sizeof(unsigned short*));
	//printf("%lu\n", sizeof(mystat.st_rdev));
	//printf("%lu\n", sizeof(mode_t));
    closedir(mydir);
}