/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:35:20 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/16 15:43:49 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

t_flags *ft_flag_ini(void)
{
	t_flags *flag;

	flag = (t_flags *)malloc(sizeof(t_flags));

	flag->flag_l = '0';
	flag->flag_a = '0';
	flag->flag_ur = '0';
	flag->flag_lr = '0';
	flag->flag_t = '0';
	flag->flag_o = '0';
	flag->flag_n = '0';
	flag->flag_g = '0';
	flag->flag_err = '0';
	flag->flag_active = '0';
	return (flag);
}

char **arguments_taker(char **str, int argument_counter)
{
	int i;
	int j;
	char **s;

	i = 1;
	j = 0; 
	s = (char**)malloc(sizeof(char*)*argument_counter * 1000);
	while(str[i] != NULL)
	{
		 if (str[i][0] != '-')
		 {
			s[j] = ft_strdup(&str[i][j]);
			j++;
		 }
		i++;
	}
	s[j] = NULL;
	return (s);
}

int main(int ac, char **av)
{
	char **new;
	char **str;
	t_flags *flag;
	int i;
	int j = 0;

	new = NULL;
	str = NULL;
	flag = ft_flag_ini();
	str = arguments_taker(av,ac);
	ft_sort(str);
	if (str[0] == NULL)
	{
		str[j] = ft_changer(av);
		str[j+1] = NULL;
	}
	if (ac >= 2)
	{
		//flag_saver(av,flag);
		check_flags(av,flag);
		while (str[j] && flag->flag_err == '0')
		{
			if(array_counter(str) > 1)
			{
				ft_putstr(str[j]);
				ft_putendl(":");
			}
			new = ft_content(new, flag, &str[j]);
			i = 0;
			if (flag->flag_l == '1')
				ft_file_info(new, str[j]);
			while(new[i] != NULL && flag->flag_l == '0')
			{
				ft_putendl(new[i++]);
			}
			ft_putchar('\n');
			j++;
		}
	}
	i = 0;
	if (ac == 1 )
	{
		new = ft_content(new, flag, str);
		while (new[i] != NULL)
			ft_putendl(new[i++]);
	}
	return (0);
}
