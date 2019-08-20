/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:45:33 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/20 11:01:29 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

int		ft_count_array(char **new)
{
	int		a;

	a = 0;
	while (new[a] != NULL)
		a++;
	return (a);
}

char **ft_reverse(char **new)
{
	char **str;
	int i;
	int j;

	i = 0;
	j = ft_count_array(new) - 1;
	str = (char **)malloc(sizeof(char *) * (j + 1));
	while(j >= 0)
	{
		str[i++] = ft_strdup(new[j--]);
	}
	str[i] = NULL;
	return (str);
}
