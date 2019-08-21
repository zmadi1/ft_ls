/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:50:14 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/21 08:43:06 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

int		check_flags(char *str,t_flags *flags)
{
	if (str[0] == '-')
	{
			if (ft_strchr(str,'l'))
			{
				flags->flag_l = '1';
				printf ("l_flag");
			}
			if (ft_strchr(str,'a'))
			{
				flags->flag_a = '1';
				printf("a_flag");
			}
			if (ft_strchr(str,'r'))
			{
				flags->flag_r = '1';
				printf("r_flag");
			}
			if (ft_strchr(str,'t'))
			{
				flags->flag_t = '1';
				printf("t_flag");
			}
			if (ft_strchr(str,'o'))
			{
				flags->flag_o = '1';
				printf("o_flag");
			}
			if (ft_strchr(str,'R'))
			{
				flags->flag_R = '1';
				printf("R_flag");
			}
			if (ft_strchr(str,'n'))
			{
				flags->flag_n = '1';
				printf("n_flag");
			}
			if (ft_strchr(str,'g'))
			{
				flags->flag_g = '1';
				printf("g_flag");
			}
			printf("\n");
	}
	return 1;
}

int		ls_flag_error_handling(char *str, t_flags *flag)
{
	char *temp;
	
	temp = str;

	if (temp[0] != '-' || (temp[0] == '-' && !temp[1]))
		return 0;
	if (temp[0] == '-' && temp[1] == '-' && !temp[2])
		return 1;
	if (temp[0] == '-')
	{
		temp++;
		while (*temp == 'l' || *temp == 'r' || *temp == 'R' ||
		
				*temp == 'o' || *temp == 'n' || *temp == 'g' ||
				*temp == 'a' || *temp == 't')
		{
			
			temp++;
			
		}
		if (*temp)
		{
			ft_putstr("ls: invalid option --");
			ft_putchar(*temp);
			ft_putstr("\nUse: ls [ - ] [alrtnogR] [file ..]\n");
			exit(0);
		}
		else
		{
			check_flags(str,flag);
		}
	}
	return (1);
}


