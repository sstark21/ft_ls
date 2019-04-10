#include "ft_ls.h"

void	my_putnbr(size_t n)
{
	if (n >= 10)
	{
		my_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

void	print_permissions(mode_t st_mode, size_t d_type)
{
	const char *permission;
	size_t i;
	
	permission = "rwxrwxrwx";
	i = 0;
	if (d_type == 4)
		write(1, "d", 1);
	else
		write(1, "-", 1);
	while (i < 9)
	{
		if (st_mode & (1 << (8 - i)))
			write(1, &permission[i], 1);
		else
			write(1, "-", 1);
		i++;
	}
	write(1, "  ", 2);
}

size_t	find_max(char *dir, int flags)
{
	DIR *mydir;
	struct dirent *myfile;
	struct stat mystat;
	struct stat mystat_max;
	size_t i;

	mystat_max = mystat;
	mydir = opendir(dir);
	i = 0;
	if (flags == 1)
	{
		while((myfile = readdir(mydir)) != NULL)
		{
			stat(myfile->d_name, &mystat);
			if (mystat.st_nlink > mystat_max.st_nlink)
				mystat_max = mystat;
		}
	}
	return((size_t)mystat_max.st_nlink);
}

void	link_count(size_t link, size_t spaces)
{
	size_t diff;
	size_t link_copy;

	link_copy = link;
	printf("===%lu===", link);
	while((link_copy = link_copy / 10) >= 1)
		diff++;
	printf("===%lu===", diff);
	//printf("-- %lu == %lu --", spaces, diff);
	// while ((spaces = spaces / 10) >= 1 && spaces < diff)
	// 	{
	// 		write(1, " ", 1);
	// 		printf("-- %lu --", spaces);
	// 	}
	// my_putnbr(link);
}

