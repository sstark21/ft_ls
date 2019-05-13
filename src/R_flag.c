/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   R_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:48:26 by sstark            #+#    #+#             */
/*   Updated: 2019/05/13 14:25:40 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		recursive_flag(char *dir)
{
	DIR *mydir;
	struct dirent *myfile;
	mydir = opendir(dir);
	char *path;

	while((myfile = readdir(mydir)) != NULL)
	{
		my_putendl(myfile->d_name, ft_strlen(myfile->d_name));
		write(1, "     ", 6);
	}
	write(1, "\n\n", 2);
	mydir = opendir(dir);
	myfile = readdir(mydir);
	while ((ft_strcmp(myfile->d_name, ".") == 0) || (ft_strcmp(myfile->d_name, "..") == 0))
	{		
		myfile = readdir(mydir);
		if (!myfile)
		{
			closedir(mydir);
			return (0);
		}
	}
	while(myfile)
	{
		if (!((ft_strcmp(myfile->d_name, ".") == 0) || (ft_strcmp(myfile->d_name, "..") == 0)))
		{
			if (((size_t)myfile->d_type == 4))
			{
                my_putendl(ft_strjoin(ft_strjoin(dir, "/"), myfile->d_name), ft_strlen(ft_strjoin(ft_strjoin(dir, "/"), myfile->d_name)));
                write(1, ":\n", 3);
				recursive_flag(ft_strjoin(ft_strjoin(dir, "/"), myfile->d_name));				
			}
		}
		if (mydir)
			myfile = readdir(mydir);
		else
			break;
	}
	return(0);
}