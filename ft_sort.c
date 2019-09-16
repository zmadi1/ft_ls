/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:18:57 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/16 12:02:34 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

void	ft_sort(char **new)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (new[i] != NULL)
	{
		j = i + 1;
		while (new[j] != NULL)
		{
			if (ft_strcmp(new[i], new[j]) > 0)
			{
				str = ft_strdup(new[i]);
				new[i] = ft_strdup(new[j]);
				new[j] = ft_strdup(str);
				free(str);
			}
			j++;
		}
		i++;
	}
}
