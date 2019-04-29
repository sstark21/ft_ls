#include "ft_ls.h"

lst_inf	*cr_struct(DIR *mydir)
{
	lst_inf	*inf;
	struct dirent *myfile;
	struct stat	mystat;
	struct passwd *pass;
	struct tm	*time;
	struct group *gr;

	if (!(inf = (lst_inf*)malloc(sizeof(lst_inf))))
		return NULL;
	myfile = readdir(mydir);
	stat(myfile->d_name, &mystat);
	inf->perm.type_file = (size_t)myfile->d_type;
	inf->perm.perm = mystat.st_mode;	
	inf->name = myfile->d_name;
	inf->links = (size_t)mystat.st_nlink;
	inf->user = ((pass = getpwuid(mystat.st_uid))->pw_name);
	inf->group = ((gr = getgrgid(mystat.st_uid))->gr_name);
	inf->size = (size_t)mystat.st_size;
	inf->time = (char *)localtime(&mystat.st_mtimespec.tv_sec);
	inf->next = NULL;
	return (inf);
}

lst_inf	**cr_lists(char *dir)
{
	DIR	*mydir;
	struct dirent *myfile;
	lst_inf **new_st;
	lst_inf **cp_new_st;

	mydir = opendir(dir);
	*new_st = cr_struct(mydir);
	cp_new_st = new_st; 
	while ((myfile = readdir(mydir)) != NULL)
	{
		(*new_st)->next = cr_struct(mydir);
		*new_st = (*new_st)->next;
	}
	return (cp_new_st);
}