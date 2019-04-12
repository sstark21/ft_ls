#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <grp.h>


#define YEAR 31536000
#define DAY 86400 

void	print_permissions(mode_t st_mode, size_t d_type);
void	space_count(size_t link, size_t spaces);
void	my_putnbr(size_t n);
void	find_flags(char *flags, char *dir);
void	l_flag(char *dir);
size_t	find_max(char *dir, int flags);
void	print_time(char *time);
void	no_flags(char *dir);