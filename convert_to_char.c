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

void	my_putendl(char *str, size_t len)
{
	while(len--)
		write(1, str++, 1);
}

void	print_permissions(mode_t st_mode, size_t d_type)
{
	const char *permission;
	size_t i;
	
	permission = "rwxrwxrwx";
	i = 0;
	if (d_type == 4)
		write(1, "d", 1);
	else if (d_type == 10)
		write(1, "l", 1);
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
		return((size_t)mystat_max.st_nlink);
	}
	if (flags == 2)
	{
		while((myfile = readdir(mydir)) != NULL)
		{
			stat(myfile->d_name, &mystat);
			if (mystat.st_size > mystat_max.st_size)
				mystat_max = mystat;
		}
		return((size_t)mystat_max.st_size);
	}
	return (0);
}

void	space_count(size_t link, size_t spaces)
{
	size_t diff;
	size_t link_copy;
	size_t spaces_diff;

	diff = 0;
	spaces_diff = 0;
	link_copy = link;
	while((link_copy = link_copy / 10) >= 1)
		diff++;
	while((spaces = spaces / 10) >= 1)
		spaces_diff++;
	while((spaces_diff - diff) > 0)
		{
			write(1, " ", 1);
			diff++;
		}
	my_putnbr(link);
	write(1, "  ", 1);
}

void	print_time(char *time)
{
	short i;

	i = 4;
	while (i <= 15)
	{
		write(1, &time[i], 1);
		i++;
	}
	write(1, " ", 1);
}


// int	recursive_flag(char *dir)
// {																				
// 	DIR *mydir;
// 	struct dirent *myfile;
// 	mydir = opendir(dir); //DEB()
// 	// dir = "./git/branches";
// 	// mydir = opendir(dir); DEB()
// // 	if (!(myfile))
// // 	{
// // //		closedir(mydir);
// // 		myfile = readdir(mydir);
// // 		//printf("%s\n", myfile->d_name);
// // 	}
// 	if (mydir)
// 	{
// 		write(1, "HERE\n", 5);
// 		myfile = readdir(mydir);
// 		//my_putendl(myfile->d_name, (size_t)myfile->d_namlen);
// 	}
// 	while (myfile)
// 	{
// 		//my_putnbr(myfile->d_namlen);
// 		ft_putendl(myfile->d_name);
// 		//write(1, myfile->d_name, (size_t)myfile->d_namlen);
// 		//my_putendl(myfile->d_name, (size_t)myfile->d_namlen + 1);
// 		write(1, "\n", 1);
// 		//my_putnbr(((size_t)myfile->d_reclen) - ((size_t)myfile->d_ino) - ((size_t)myfile->d_name) - ((size_t)myfile->d_type));
		
// 		//printf("(%hu == %hu)\n", myfile->d_reclen, myfile->d_namlen);
// //DEBst() DEBtextt("DIR_name", myfile->d_name) DEBend()
// 		if (!((ft_strcmp(myfile->d_name, ".") == 0) || (ft_strcmp(myfile->d_name, "..") == 0)))
// 		{
// 			if (((size_t)myfile->d_type == 4))
// 			{
// 				recursive_flag(myfile->d_name);				
// 			}
// 		}
// 		if (mydir)
// 			myfile = readdir(mydir);
// 		else
// 			break;
		
// 	}
// 	DEBex("Got 0") return (0);
// }

int		recursive_flag(char *dir)
{
	DIR *mydir;
	struct dirent *myfile;
	mydir = opendir(dir);

	while((myfile = readdir(mydir)) != NULL)
	{
		ft_putendl(myfile->d_name);
		write(1, "  ", 3);
	}
	write(1, "\n\n", 2);
	mydir = opendir(dir);
	myfile = readdir(mydir);
	//printf("____%s\n____", myfile->d_name);
	while ((ft_strcmp(myfile->d_name, ".") == 0) || (ft_strcmp(myfile->d_name, "..") == 0))
	{		
		myfile = readdir(mydir);
		if (!myfile)
		{
			closedir(mydir);
			return (0);
		}
	}
DEB()
	while(myfile)
	{
DEB()
// 		if (((size_t)myfile->d_type == 4))
// 		{
// 			ft_putendl(myfile->d_name);
// 			write(1, ":", 1);
// DEB()
// 			recursive_flag(myfile->d_name);			
// 		}
// 		else
// 			myfile = readdir(mydir);
	if (!((ft_strcmp(myfile->d_name, ".") == 0) || (ft_strcmp(myfile->d_name, "..") == 0)))
	{
		if (((size_t)myfile->d_type == 4))
		{
			recursive_flag(myfile->d_name);				
		}
	}
	if (mydir)
		myfile = readdir(mydir);
	else
		break;
	}
	return(0);
}