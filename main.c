/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:35:20 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/29 14:32:17 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

t_flags *ft_flag_ini(void)
{
	t_flags *flag;

	flag = (t_flags *)malloc(sizeof(t_flags));

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

char **arguments_taker(char **str, int argument_counter)
{
	int i;
	int j;
	char **s;

	i = 1;
	j = 0; 
	s = (char**)malloc(sizeof(char*)*argument_counter);
	while(str[i] != NULL)
	{
		if (str[i][0] != '-')
		{
			s[j] = ft_strdup(str[i]);
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
	// DIR *pdir;
	t_flags *flag;
	// struct dirent *files;
	int i;
	int j = 0;

	new = NULL;
	flag = ft_flag_ini();
	str = arguments_taker(av,ac);
	ft_sort(str);
	if (ac > 1)
	{
		while (j < ac && str[j])
		{
			// ft_putnbr(j);
			i = ls_flag_error_handling(av[j + 1], flag);
			if(array_counter(str) > 1)
			{
				ft_putstr(str[j]);
				ft_putendl(":");
			}
			new = ft_content(new, flag, str[j]);
			j++;
			// ft_putnbr(j);
			ft_putchar('\n');
		}
		i = 0;
		while(new[i] != NULL && flag->flag_l == '0')
		{
			ft_putendl(new[i++]);
		}
	}
	//new = ft_content(new, flag, ".");
	i = 0;
	if (ac == 1)
	{
		new = ft_content(new, flag, ".");
		while (new[i] != NULL)
			ft_putendl(new[i++]);
	}
	// if (files->d_type == 4)
	// {
	// 	dir = opendir(dir);
	// }
	return (0);
}
