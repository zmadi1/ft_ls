/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:07:57 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/16 15:12:52 by zmadi            ###   ########.fr       */
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
	ft_sort(dir);
	return (dir);
}

char **ft_content(char **new, t_flags *flag, char **dir)
{
	int i = 0;
	DIR *curdir;
	struct dirent *files;
	int j = 0;
	char **temp;

	temp = (char **)malloc(sizeof(char *) * 256);
	//ft_putendl("1");
	new = (char **)malloc(sizeof(char *) * count(dir[j]) + 1);
	ft_putendl("wolrd");
	//ft_putendl("2");
	curdir = opendir(*dir);
	if(!curdir)
		ft_protector(new, *dir);
	while (curdir && (files = readdir(curdir)) != NULL)
	{
		//ft_putendl("9");
		// ft_putendl("Here");
		if (flag->flag_a == '0' && files->d_name[0] != '.')
		{
			
			new[i++] = ft_strdup(files->d_name);
			if (flag->flag_ur == '1' && files->d_type == 4 && (ft_strcmp(files->d_name, ".") != 0) && (ft_strcmp(files->d_name, "..") != 0))
			{
			
				temp[j++] = ft_path(files->d_name,*dir);
				temp[j] = NULL;
			

				//ft_putendl(ft_path(files->d_name,*dir));
				// exit(0);
				// ft_putendl(*dir)
			}
				
		}
		if(flag->flag_a == '1')
		{
			new[i++] = ft_strdup(files->d_name);
			if (flag->flag_ur == '1' && files->d_type == 4 && (ft_strcmp(files->d_name, ".") != 0) && (ft_strcmp(files->d_name, "..") != 0))
			{
				//exit(0);
				temp[j++] = ft_path(files->d_name,*dir);
				temp[j] = NULL;//store path name 
			}
		}
	}
		temp[j] = NULL;
	// exit(0);
	if (curdir)
	{
		closedir(curdir);
		new[i] = NULL;
	}
	ft_sort(new);
	if (flag->flag_t == '1')
		new = ft_time_sort(new, *dir);
	if (flag->flag_lr == '1')
		new = ft_reverse(new);	
	dir = temporary_function(dir,temp);
	ft_putchar('\n');
	return (new);
}
