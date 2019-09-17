/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_counterfunc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:04:29 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/17 17:41:43 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

void ft_protector(char **new, char *dir)
{
	if (errno == 2)
	{
		ft_putstr("ft_ls: ");
        ft_putstr(dir);
        ft_putendl(": No such file or directory");
        exit(0);
	}
	if (errno == 13)
	{
       ft_putstr("ft_ls: ");
       ft_putstr(dir);
       ft_putendl(": Permission denied"); 
	}
	if (errno == 20)
	{
        new[0] = ft_strdup(dir);
        new[1] = NULL;
        ft_file_info(new,dir);
		ft_strdel(&new[0]);
		ft_strdel(&new[1]);
		free(new);
	}
}

