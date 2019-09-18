/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timesort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:36:06 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/18 14:50:30 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

void	ft_swap(char **new, int a, int b)
{
	char *temp;

	temp = ft_strdup(new[a]);
	ft_strdel(&new[a]);
	new[a] = ft_strdup(new[b]);
	ft_strdel(&new[b]);
	new[b] = ft_strdup(temp);
	ft_strdel(&temp);
}

char	**ft_time_sort(char **new, char *dir)
{
	struct stat a;
	struct stat b;
	char *str;
	int i;
	int j;

	i = 0;
	while (new[i])
	{
		j = i + 1;
		while (new[j])
		{
			stat((str = ft_path(new[i], dir)), &a);
			ft_strdel(&str);
			stat((str = ft_path(new[j], dir)), &b);
			ft_strdel(&str);
			if(a.st_mtimespec.tv_sec < b.st_mtimespec.tv_sec)
				ft_swap(new, i, j);
			if(a.st_mtimespec.tv_sec == b.st_mtimespec.tv_sec)
			{
				if(a.st_mtimespec.tv_nsec < b.st_mtimespec.tv_nsec)
					ft_swap(new, i, j);
				if(a.st_mtimespec.tv_nsec == b.st_mtimespec.tv_nsec)
					if (ft_strcmp(new[i],new[j]) < 0)
						ft_swap(new, i, j);
			}
			j++;
		}
		i++;
	}
	return(new);
}
