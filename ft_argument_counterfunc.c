/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_counterfunc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:04:29 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/30 16:06:35 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

char *flag_saver(char **str)
{
	char *s;
	int i;

	i = 0;
	s = ft_strdup("");
	while (str[i] != NULL)
	{
		if (str[i][0] == '-')
		{
			s = ft_strjoin(s, str[i]);
			ft_putendl(s);
		}
	
		i++;
	}
	
	return (s);
}
