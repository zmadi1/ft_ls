/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_counterfunc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:04:29 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/16 15:45:49 by zmadi            ###   ########.fr       */
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
        // if(flag->flag_l == '1')
        //     ft_file_info(new,dir);
    }
 }

void flag_saver(char **str,t_flags *flags)
{
    int i;
    int j;
	// char **new;

    i = 1;
    j = 0;
	// new = NULL;
    while (str[i] != NULL)
    {
        //checking if str[i] is a file / directory
        if (str[i])
        {
            
            if(str[i][0] != '-')
            {
                
                ft_putstr("No such file or directory-- ");
            }
        }
        // checking if str[i] a flag
        if (str[i][j] == '-' && ft_isalpha(str[i][i]))
        {
            ft_putendl(str[i]);
			check_flags(&str[i],flags);
        }
		else
		{
			ft_putstr("ls: invalid option --  ");
			ft_putchar(*str[i]);
			ft_putstr("\nUse: ls [ - ] [alrtnogR] [file ..]\n");
			exit(0);
		}
		
        i++;
    }
}
