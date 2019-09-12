/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:07:57 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/12 15:52:09 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"
#include <stdio.h>
int count_dir(char *dir)
{

	int i;
	DIR *curdir;
	struct dirent *files;

	i = 0;
	curdir = opendir(dir);

	while ((files = readdir(curdir)) != NULL)
	{
		if (files->d_type == 4)
			i++;
	}
	closedir(curdir);
	return (i);
}

char **temporary_function(char **dir, char **temp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(dir[i] != NULL)
	{
		i++;
	}
	while(temp[j] != NULL)
	{
		dir[i++] = ft_strdup(temp[j++]);
	}
	dir[i] = NULL;
	return (dir);
}

char **ft_content(char **new, t_flags *flag, char **dir, int k)
{
	int i = 0;
	DIR *curdir;
	struct dirent *files;
	int j = 0;
	char **temp;

	temp = (char **)malloc(sizeof(char *) * 256);
	ft_putendl("1");
	new = (char **)malloc(sizeof(char *) * count(dir[j]) + 1);
	ft_putendl("2");
	curdir = opendir(*dir);
	 ft_putendl(dir[k]);
	while ((files = readdir(curdir)) != NULL)
	{
		ft_putendl("9");
		// ft_putendl("Here");
		if (flag->flag_a == '0' && files->d_name[0] != '.')
		{
			ft_putendl("8");
			new[i++] = ft_strdup(files->d_name);
			ft_putendl(files->d_name);
			// if (flag->flag_R == '1' && files->d_type == 4 && (ft_strcmp(files->d_name, ".") != 0) && (ft_strcmp(files->d_name, "..") != 0))
			// {
			// 	temp[j++] = ft_path(files->d_name,dir[k]);
			// 	temp[j] = NULL;
			// }
		}
		if(flag->flag_a == '1')
		{
			new[i++] = ft_strdup(files->d_name);
			// if (flag->flag_R == '1' && files->d_type == 4 && (ft_strcmp(files->d_name, ".") != 0) && (ft_strcmp(files->d_name, "..") != 0))
			// {
			// 	temp[j++] = ft_path(files->d_name,dir[k]);
			// 	temp[j] = NULL;
			// }
		}

		// if(files->d_type == 4)
		// {
		// 	curdir = opendir(files->d_name);
		// 	while ((files = readdir(curdir)) != NULL)
		// 	{
		// 		recur_new[i] = ft_path(files->d_name,dir);
		// 		ft_putendl(recur_new[i]);
		// 		i++;
		// 	}
		// 	ft_putchar('\n');
		// 	// ft_content(new,flag,dir);
		// }
	}
	closedir(curdir);
	new[i] = NULL;

	ft_sort(new);
	if (flag->flag_t == '1')
		new = ft_time_sort(new, dir[k]);
	if (flag->flag_r == '1')
		new = ft_reverse(new);
	// if (flag->flag_l == '1')
	// 	ft_file_info(new, dir[k]);
	// if (recur_new != NULL)
	// {
	// 	ft_sort(recur_new);
	// 	ft_time_sort(recur_new,dir);
	// 	ft_file_info(recur_new,dir);
	// 	while(recur_new[i])
	// 	{
	// 		ft_content(new,flag,recur_new[i]);
	// 		i++;
	// 	}
	// }
	dir = temporary_function(dir,temp);
	ft_putchar('\n');
	return (new);
}
