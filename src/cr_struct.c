/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rootuser <rootuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:57:01 by sstark            #+#    #+#             */
/*   Updated: 2019/05/21 11:51:06 by rootuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/* Заолняем нашу структуру данными */

lst_inf	*cr_struct(struct dirent *myfile)
{
	lst_inf	*inf;
	lst_inf cp_inf;
	struct stat	mystat; /* тут основная инфа о файле, есть в конспекте */
	struct passwd *pass; /* имя юзера*/
	//struct tm	*time;
	struct group *gr; /* имя группы*/

	//printf("---%s---\n", myfile->d_name);
	// if (!(inf = (lst_inf*)malloc(sizeof(lst_inf))))
	// 	return NULL;
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

/* Тут мы получаем на вход указатель на дерикторию которую должны считать 
и двигаясь поэлементно создаем листы получая (пока что) односвязный список*/

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
	new_st = cr_struct(myfile); /* тут мы заполняем первый элемент*/
	cp_new_st = new_st; /* тут копируем ссылку на первый элемент*/
	
	while (myfile) /* ну и пока можем гонять по папке, создаем список заполненный структурами*/
	{
DEBst() DEBlt("size of lst_inf", sizeof(lst_inf)) DEBend()
		new_st->next = (lst_inf*)ft_memalloc(sizeof(lst_inf)); /* надо запилить маллок эксит, 
																кторый будет проверять безопасность и если че выходить экзитом*/
		cr_struct(myfile);
		myfile = readdir(mydir);
DEBst() DEBit("FILE", myfile) DEBit("current", new_st) DEBit("NEXT", new_st->next) DEBend()
			new_st = new_st->next;
	}
DEB()
	//printf("---%s---\n", cp_new_st);
	return (cp_new_st); /* возвращаем указатель на первый элемент списка*/
}