/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:07:57 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/19 15:58:48 by zmadi            ###   ########.fr       */
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

char **ft_content(char **new)
{
	int i = 0;
	DIR *curdir;
	struct dirent *files;

	new = (char **)malloc(sizeof(char *) * count() + 1);
	curdir = opendir(".");
	while ((files = readdir(curdir)) != NULL)
		new[i++] = ft_strdup(files->d_name);
	new[i] = NULL;
	closedir(curdir);
	return (new);
}
