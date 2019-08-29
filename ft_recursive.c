/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:19:30 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/27 08:20:03 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"


		if(files->d_type == 4 && flag->flag_R == '1' && flag->flag_a == '0' && files->d_name[0] != '.')
		{

			new = (char **)malloc(sizeof(char*) * count_dir(dir));
			new[i++] = ft_strdup(files->d_name);
			ft_putstr(new[0]);
			ft_content(new,flag,dir);

			ft_putstr(new[0]);
        }