/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timesort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:36:06 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/21 12:52:22 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

void	ft_swap(char **new, int a, int b)
{
	char *tmp;

	tmp = ft_strdup(new[a]);
	new[a] = ft_strdup(new[b]);
	new[b] = ft_strdup(tmp);
}

char	**ft_time_sort(char **new, char *dir)
{
	struct stat a;
	struct stat b;
	int i;
	int j;

	i = 0;
	while (new[i])
	{
		j = i + 1;
		while (new[j])
		{
			stat(ft_path(new[i], dir), &a);
			stat(ft_path(new[j], dir), &b);
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
