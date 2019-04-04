#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>



void    fake_printf_la(const char *str, ... );
void	my_putnbr(size_t n);
void	print_size(size_t size);
void	print_name(char *str);
void    print_permissions(mode_t mode, size_t c);
