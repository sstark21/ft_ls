#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include "../libft/includes/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <grp.h>
#include <sys/ioctl.h>

void	print_permissions(mode_t st_mode, size_t d_type);
void	space_count(size_t link, size_t spaces);
void	my_putnbr(size_t n);
void	find_flags(char *flags, char *dir);
void	l_flag(char *dir);
size_t	find_max(char *dir, int flags);
void	print_time(char *time);
void	no_flags(char *dir);
int 	recursive_flag(char *dir);
void	my_putendl(char *str, size_t len);
int		ioctl_space(char *dir);
//void	find_flags(int ac, char **av);

typedef struct			permissions
{
	size_t				perm;
	size_t				type_file;
}						file_perm;

typedef struct			file_info
{
    file_perm			perm;
    size_t				links;
	char				*name;
	char				*user;
    char				*group;
    size_t				size;
    char				*time;
	short				hide;
	struct file_info	*next;

}						lst_inf;


lst_inf	*cr_struct(struct dirent *myfile);
lst_inf	*cr_lists(char *dir);


# define DEBst() printf("\t\033[0;31m%d\033[0m in:\t%s \t\t", __LINE__, __func__); 
# define DEBend() printf("\n"); 
# define DEBit(name, x) printf("\033[1;35m%s\033[0m == %p ", (name), (x)); 
# define DEBintt(name, x) printf("\033[1;35m%s\033[0m == %d ", (name), (x)); 
# define DEBlt(name, x) printf("\033[1;35m%s\033[0m == %zu ", (name), (x)); 
# define DEBtextt(name, x) printf("[\033[1;35m%s\033[0m] == [%s] ", (name), (x)); 
# define DEBmesst(name) printf("\033[1;36m%s\033[0m ", (name)); 
# define DEBfunc() printf("\033[0;33mEntering\033[0m MY:\t\033[0;33m%s\033[0m of file \"%s\"\n", __func__, __FILE__); 
# define DEB() printf("\t\033[0;31m%d\033[0m in:\t%s\n", __LINE__, __func__); 
# define DEBex(name) printf("\033[0;32mExiting \033[0m MY:\t\033[0;32m%s\033[0m,%s\n\n", __func__, (name)); 
# define DEBprog() printf("\n\nENTRANCE IN \033[0;33m~~~~~~~~~~~~~~~~%s~~~~~~~~~~~~~~~~\033[0m\n", __FILE__); 
# define DEBm() printf("Malloc failed at line \033[0;31m%d\033[0m in function: %s\n", __LINE__, __func__); 
# define DEBi(name, x) printf("\033[0;31m%d\033[0m str in func: %s, \"\033[1;35m%s\033[0m\" adress %p\n", __LINE__, __func__, (name), (x)); 
# define DEBtext(name, x) printf("\033[0;31m%d\033[0m str in func: %s, arr:[%s] == [%s]\n", __LINE__, __func__, (name), (x)); 
# define DEBl(name, x) printf("\033[0;31m%d\033[0m str in func: %s, %s == %zu\n", __LINE__, __func__, (name), (x)); 
# define DEBint(name, x) printf("\033[0;31m%d\033[0m str in func: %s, %s == %d\n", __LINE__, __func__, (name), (x)); 