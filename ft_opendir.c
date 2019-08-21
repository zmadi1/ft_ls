/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:07:57 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/21 12:46:16 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"
#include <stdio.h>
int count(void)
{
	int i = 0;
	DIR *curdir;
	struct dirent *files;

	curdir = opendir(".");

	while ((files = readdir(curdir)) != NULL)
		i++;
	closedir(curdir);
	return (i);
}

char **ft_content(char **new, t_flags *flag)
{
	int i = 0;
	DIR *curdir;
	struct dirent *files;

	new = (char **)malloc(sizeof(char *) * count() + 1);
	curdir = opendir(".");
	while ((files = readdir(curdir)) != NULL)
	{
		if (flag->flag_a == '0' && files->d_name[0] != '.')
			new[i++] = ft_strdup(files->d_name);
		if (flag->flag_a == '1')
			new[i++] = ft_strdup(files->d_name);
	}
	
	closedir(curdir);
	new[i] = NULL;
	ft_sort(new);
	if(flag->flag_t == '1')
		ft_time_sort(new);
	if(flag->flag_r == '1')
		new = ft_reverse(new);
	if (flag->flag_l == '1')
		ft_file_info(new);
	return (new);
}
