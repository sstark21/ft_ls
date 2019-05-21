/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   R_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rootuser <rootuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:48:26 by sstark            #+#    #+#             */
/*   Updated: 2019/05/21 12:02:54 by rootuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

/*
	ищет максимальное слово и возвразает его длину
*/

int		find_max_word(char *dir)
{
	char *max_name;
	DIR *mydir;
	struct dirent *myfile;
	
	mydir = opendir(dir);
	myfile = readdir(mydir);
	max_name = myfile->d_name;
	while (myfile)
    {	
        if (ft_strlen(max_name) < ft_strlen(myfile->d_name))
				max_name = myfile->d_name;
		else
				myfile = readdir(mydir);
    }
	return (ft_strlen(max_name));
}

/*
	ищет ширину окна
*/

int		ioctl_space(char *dir)
{
	int max_word_len;
	struct winsize w;
	unsigned short win_size;

	max_word_len = find_max_word(dir);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	win_size = w.ws_col;
	return (win_size);
}

/*
	ну тут ты в курсе
*/

int		recursive_flag(char *dir)
{
	// DIR *mydir;
	// struct dirent *myfile;
	// mydir = opendir(dir);
	// char *path; 
	lst_inf *first;
	lst_inf *cp_first;
	
	first = cr_lists(dir);
	printf("first - %s\n", first->name);
	printf("second - %s\n", (first->next)->name);
	// while((myfile = readdir(mydir)) != NULL)
	// {
	// 	my_putendl(myfile->d_name, ft_strlen(myfile->d_name));
	// 	write(1, "     ", 6);
	// }
	// write(1, "\n\n", 2);
	// mydir = opendir(dir);
	// myfile = readdir(mydir);

	// while ((ft_strcmp(myfile->d_name, ".") == 0) || (ft_strcmp(myfile->d_name, "..") == 0))
	// {		
	// 	myfile = readdir(mydir);
	// 	if (!myfile)
	// 	{
	// 		closedir(mydir);
	// 		return (0);
	// 	}
	// }
	// while(myfile)
	// {
	// 	if (((size_t)myfile->d_type == 4))
	// 	{
	// 		my_putendl(ft_strjoin(ft_strjoin(dir, "/"), myfile->d_name), ft_strlen(ft_strjoin(ft_strjoin(dir, "/"), myfile->d_name)));
	// 		write(1, ":\n", 3);
	// 		recursive_flag(ft_strjoin(ft_strjoin(dir, "/"), myfile->d_name));				
	// 	}
	// 	if (mydir)
	// 		myfile = readdir(mydir);
	// 	else
	// 		break;
	// }
	while(first->next)
	{
		printf("LOL");
		printf("first_name %s\n", first->name);
		first = first->next;
	}
	while(first->next)
	{
		printf("HERE\n");
		if (first->perm.type_file == 4)
		{
			my_putendl(ft_strjoin(ft_strjoin(dir, "/"), first->name), ft_strlen(ft_strjoin(ft_strjoin(dir, "/"), first->name)));
			write(1, ":\n", 3);
			recursive_flag(ft_strjoin(ft_strjoin(dir, "/"), first->name));				
		}
		// if (mydir)
		// 	myfile = readdir(mydir);
		else
			first = first->next;
	}
	return(0);
}