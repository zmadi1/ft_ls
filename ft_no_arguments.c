/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:05:22 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/18 08:06:05 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"


void	ft_no_argument(char **str, t_flags *flag)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = NULL;
	new = ft_content(new, flag, str);
	while (new[i] != NULL)
		ft_putendl(new[i++]);
		i =0;
	while(new[i])
	{
		ft_strdel(&new[i]);
		i++;
	}
	ft_strdel(new);
}
