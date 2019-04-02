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
        //fake_printf("%s  ", myfile->d_name);
		//fake_printf("%h  ", &mystat.st_nlink);
		my_putnbr(mystat.st_nlink);
		write(1, "\n", 1);
		//printf("%lld", mystat->st_size);
    }
	//printf("%lu\n%lu\n%lu\n", sizeof(int), sizeof(unsigned short), sizeof(unsigned short*));
	//printf("%lu\n", sizeof(mystat.st_rdev));
    closedir(mydir);
}