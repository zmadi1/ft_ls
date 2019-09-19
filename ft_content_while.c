/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_while.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 07:18:19 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/19 08:52:34 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

void	ft_content_while(char **new, char **temp, t_flags *flag, char **dir, DIR *curdir)
{
	int				i;
	int				j;
	struct dirent	*files;

	i = 0;
	j = 0;
	while ((files = readdir(curdir)) != NULL)
	{
		if (flag->flag_a == '0' && files->d_name[0] != '.')
		{
			new[i++] = ft_strdup(files->d_name);
			if (flag->flag_ur == '1' && files->d_type == 4 && (ft_strcmp(files->d_name, ".") != 0) && (ft_strcmp(files->d_name, "..") != 0))
			{
				temp[j++] = ft_path(files->d_name, *dir);
				temp[j] = NULL;
			}
		}
		if (flag->flag_a == '1')
		{
			new[i++] = ft_strdup(files->d_name);
			if (flag->flag_ur == '1' && files->d_type == 4 && (ft_strcmp(files->d_name, ".") != 0) && (ft_strcmp(files->d_name, "..") != 0))
			{
				temp[j++] = ft_path(files->d_name, *dir);
				temp[j] = NULL;
			}
		}
	}
	new[i] = NULL;
}
