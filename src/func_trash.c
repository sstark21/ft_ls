
// #include "ft_ls.h"

// void	my_putnbr(size_t n)
// {
// 	if (n >= 10)
// 	{
// 		my_putnbr(n / 10);
// 		ft_putchar(n % 10 + '0');
// 	}
// 	else
// 		ft_putchar(n + '0');
// }


// void	print_name(char *str)
// {
// 	ft_putendl(str);
// }

// void	print_size(size_t size)
// {
// 	my_putnbr(size);
// }

/*			FAKE PRINTF


void	fake_printf_la(const char *str, ... )
{
	int i;
	va_list vl;
	va_start(vl, str);

	i = 0;
	while (str[i])
	{
		
		if (str[i] == '%')
		{
			// if (str[i + 1] == 'p')
			// 	print_permissions(va_arg(vl, size_t), va_arg(vl, size_t));
			if (str[i + 1] == 's')
				print_size(va_arg(vl, size_t));				
			if (str[i + 1] == 'n')
				print_name(va_arg(vl, char*));
			if (str[i + 1] == 'l')
				print_size(va_arg(vl, size_t));	
		}
		if (str[i] != '%' && str[i] != 'n' && str[i] != 's' && str[i] != 'p' && str[i] != 'l')
			write(1, &str[i], 1);
		i++;
		
	}
	va_end(vl);
}

*/


/*			L FLAG

 
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

*/


#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	printf("lines %d\n", w.ws_row);
	printf("columns %d\n", w.ws_col);
	return (0);
	
}