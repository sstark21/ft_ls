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


void	print_name(char *str)
{
	ft_putendl(str);
}

void	print_size(size_t size)
{
	my_putnbr(size);
}

void print_permissions(mode_t mode, size_t c) 
{
	char *buf;
	size_t i;
	const char *chars;

	i = 1;
	buf = malloc(11);
	chars = "-rwxrwxrwx";
	if (c == 4)
		buf[0] = 'd';
	else
		buf[0] = '-';
	while (i < 10) 
	{
		buf[i] = (mode & (1 << (9-i))) ? chars[i] : '-';
		i++;
	}
	buf[11] = '\0';
	print_name(buf);
}

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
			if (str[i + 1] == 'n')
				print_name(va_arg(vl, char*));
			if (str[i + 1] == 's')
				print_size(va_arg(vl, size_t));
			if (str[i+1] == 'p')
				print_permissions(va_arg(vl, size_t), va_arg(vl, size_t));
		}
		if (str[i] != '%' && str[i] != 'n' && str[i] != 's' && str[i] != 'p')
			write(1, &str[i], 1);
		i++;
		
	}
	va_end(vl);
}