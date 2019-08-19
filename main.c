/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:35:20 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/19 16:08:43 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

t_flags		*ft_flag_ini(void)
{
	t_flags *flag;

	flag = (t_flags*)malloc(sizeof(t_flags));

	flag->flag_l = '0';
	flag->flag_a = '0';
	flag->flag_R = '0';
	flag->flag_r = '0';
	flag->flag_t = '0';
	flag->flag_o = '0';
	flag->flag_n = '0';
	flag->flag_g = '0';
	return (flag);
}

int		main(int ac, char **av)
{
	char	**new;
	t_flags	*flag;
	struct	dirent 	*files;
	int		i;
	
	new = ft_content(new);
	flag = ft_flag_ini();
	i = ls_flag_error_handling(av[1], flag);
	if (flag->flag_l == '1')
		ft_file_info(new, flag);
	return (0);
}
