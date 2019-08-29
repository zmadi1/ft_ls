/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:42:20 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/24 12:01:20 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

int count(char *dir)
{
	int i;
	DIR *curdir;
	struct dirent  *files;
	i = 0;
	curdir = opendir(dir);

	while((files = readdir(curdir)) != NULL)
		i++;
	closedir(curdir);
	return (i);
}
