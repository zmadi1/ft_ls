/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:07:57 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/26 14:17:39 by zmadi            ###   ########.fr       */
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

char **ft_content(char **new, t_flags *flag, char *dir)
{
	int i = 0;
	DIR *curdir;
	char **recur_new;
	struct dirent *files;
	int j = 0;

	recur_new = NULL;
	new = (char **)malloc(sizeof(char *) * count(dir) + 1);
	recur_new = (char **)malloc(sizeof(char*) * count_dir(dir));
	curdir = opendir(dir);
	while ((files = readdir(curdir)) != NULL)
	{
		if (flag->flag_a == '0' && files->d_name[0] != '.')
			new[i++] = ft_strdup(files->d_name);
		if(flag->flag_a == '1')
				new[i++] = ft_strdup(files->d_name);
		if (files->d_type == 4)
		{
			recur_new[j++] = ft_path(files->d_name, dir);
			// ft_putendl(recur_new[j-1]);
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

	char **temp;

	closedir(curdir);
	new[i] = NULL;
	ft_sort(new);
	if (flag->flag_t == '1')
		new = ft_time_sort(new, dir);
	if (flag->flag_r == '1')
		new = ft_reverse(new);
	if (flag->flag_l == '1')
		ft_file_info(new, dir);
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
	temp = new;
	return (temp);
}
