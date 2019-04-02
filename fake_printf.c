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

void fake_printf(char *str, void *data)
{
    int i;

    i = 0;
    while ((str[i] != '%' && str[i + 1] != 's') || (str[i] != '%' && str[i + 1] != 'h'))
    {
        write(1, &str[i], 1);
        i++;
    }
    if (str[i+1] == 's')
        ft_putendl((char *) data);
    if (str[i+1] == 'h')
        my_putnbr((unsigned short) &data);
    // if (str[i+2])
    // {
    //     i += 2;
    //     while (str[i])
    //     {
    //         write (1, &str[i], 1);
    //         i++;
    //     }
    // }
}