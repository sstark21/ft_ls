/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:57:01 by sstark            #+#    #+#             */
/*   Updated: 2019/05/15 21:06:55 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

lst_inf	*cr_struct(struct dirent *myfile)
{
	lst_inf	*inf;
	lst_inf cp_inf;
	struct stat	mystat;
	struct passwd *pass;
	struct tm	*time;
	struct group *gr;

	//printf("---%s---\n", myfile->d_name);
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
	printf("---%s---\n", inf->name);
	return (inf);
}


// lst_inf	*cr_lists(char *dir)
// {
// 	DIR	*mydir;
// 	struct dirent *myfile;
// 	lst_inf *new_st;
// 	lst_inf *cp_new_st;
// 	int i;
// DEB()
// 	mydir = opendir(dir);
// 	myfile = readdir(mydir);
// 	i = 0;
// 	while ((ft_strcmp(myfile->d_name, ".") == 0) || (ft_strcmp(myfile->d_name, "..") == 0))
// 		myfile = readdir(mydir);
// 	new_st = cr_struct(myfile);
// 	cp_new_st = new_st;
	
// 	while (myfile)
// 	{
// DEB()
// 		new_st = (lst_inf*)malloc(sizeof(lst_inf));
// 		new_st = cr_struct(myfile);
// 		myfile = readdir(mydir);
// DEB()
// 		if (new_st->next)
// 			new_st = new_st->next;
// 		else
// 			break ; 	
// 	}
// DEB()
// 	//printf("---%s---\n", cp_new_st);
// 	return (cp_new_st);
// }


lst_inf	*cr_lists(char *dir)
{																				DEBfunc() DEBtext("DIR", dir)
	DIR	*mydir;
	struct dirent *myfile;
	lst_inf *new_st;
	lst_inf *cp_new_st;
	int i;
DEB()
	mydir = opendir(dir);
	myfile = readdir(mydir);
	i = 0;
	while ((ft_strcmp(myfile->d_name, ".") == 0) || (ft_strcmp(myfile->d_name, "..") == 0))
		myfile = readdir(mydir);
	new_st = cr_struct(myfile);
	cp_new_st = new_st;
	
	while (myfile)
	{
DEBst() DEBlt("size of lst_inf", sizeof(lst_inf)) DEBend()
		new_st->next = (lst_inf*)ft_memalloc(sizeof(lst_inf));
		cr_struct(myfile);
		myfile = readdir(mydir);
DEBst() DEBit("FILE", myfile) DEBit("current", new_st) DEBit("NEXT", new_st->next) DEBend()
			new_st = new_st->next;
	}
DEB()
	//printf("---%s---\n", cp_new_st);
	return (cp_new_st);
}