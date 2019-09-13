/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:50:14 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/13 13:52:49 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

int		check_flags(char **str,t_flags *flags)
{
	
	int i = 0;
	while (str[i] != NULL)
	{
		if (str[i][0] == '-')
		{
			if (ft_strchr(str[i],'l'))
			{
				flags->flag_l = '1';
				flags->flag_active = '1';
			}
			if (ft_strchr(str[i],'a'))
			{
				flags->flag_a = '1';
				flags->flag_active = '1';
				printf("a_flag");
			}
			if (ft_strchr(str[i],'r'))
			{
				flags->flag_r = '1';
				flags->flag_active = '1';
				printf("r_flag");
			}
			if (ft_strchr(str[i],'t'))
			{
				flags->flag_t = '1';
				flags->flag_active = '1';
				printf("t_flag");
			}
			if (ft_strchr(str[i],'o'))
			{
				flags->flag_o = '1';
				flags->flag_active = '1';
				printf("o_flag");
			}
			if (ft_strchr(str[i],'R'))
			{
				flags->flag_R = '1';
				flags->flag_active = '1';
				printf("R_flag");
			}
			if (ft_strchr(str[i],'n'))
			{
				flags->flag_n = '1';
				flags->flag_active = '1';
				printf("n_flag");
			}
			if (ft_strchr(str[i],'g'))
			{
				flags->flag_g = '1';
				flags->flag_active = '1';
				printf("g_flag");
			}
			if (flags->flag_active == '0')
			{
				flags->flag_err = '1';
				ft_putstr("ls: invalid option --");
				ft_putstr(str[i]);
				ft_putstr("\nUse: ls [ - ] [alrtnogR] [file ..]\n");
				return (0);
			}
			
		}
		i++;
	}
	return 1;
}