#include "ft_ls.h"

lst_inf	*cr_struct(struct dirent *myfile) //начал тут
{
	lst_inf	*inf;
	lst_inf cp_inf;
	struct stat	mystat;
	struct passwd *pass;
	struct tm	*time;
	struct group *gr;

	if (!(inf = (lst_inf*)malloc(sizeof(lst_inf))))
		return NULL;
	stat(myfile->d_name, &mystat);
	inf->perm.type_file = (size_t)myfile->d_type;
	inf->perm.perm = mystat.st_mode;
	inf->name = myfile->d_name;
	inf->links = (size_t)mystat.st_nlink;
	inf->user = ((pass = getpwuid(mystat.st_uid))->pw_name);
	inf->group = ((gr = getgrgid(mystat.st_gid))->gr_name);
	inf->size = (size_t)(mystat.st_size);
	inf->time = asctime(localtime(&mystat.st_mtimespec.tv_sec));
	inf->next = NULL;
	//cp_inf = inf;
// 	printf("%s\n", inf.name);
// 	printf("%lu\n", inf.links);
// 	printf("%s", inf.time);
// 	printf("%s\n", inf.user);
// 	printf("%s\n", inf.group);
// 	printf("%lu\n", inf.size);
// DEB()
	return (inf);
}


lst_inf	*cr_lists(char *dir)
{
	DIR	*mydir;
	struct dirent *myfile;
	lst_inf *new_st;
	lst_inf *cp_new_st;
	int i;

	mydir = opendir(dir);
	myfile = readdir(mydir);
	i = 0;
	while ((ft_strcmp(myfile->d_name, ".") == 0) || (ft_strcmp(myfile->d_name, "..") == 0))
		myfile = readdir(mydir);
	new_st = cr_struct(myfile);
	cp_new_st = new_st;
	while (myfile)
	{
		new_st = (lst_inf*)malloc(sizeof(lst_inf));
		new_st = cr_struct(myfile);
		myfile = readdir(mydir);
		printf("new_st - %s\n", new_st->name);
		new_st = new_st->next;
	}
	printf("cp_new_st - %s\n", cp_new_st->name);
	return (cp_new_st);
}
