/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_counterfunc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:04:29 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/13 15:58:11 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int isDirectory(const char *path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}

void flag_saver(char **str,t_flags *flags)
{
    int i;
    int j;
	char **new;

    i = 1;
    j = 0;
	new = NULL;
    while (str[i] != NULL)
    {
        //checking if str[i] is a file / directory
        if (str[i][j] != '-')
        {
            //i//++;
            //its a file
			ft_sort(str);
            if (is_regular_file(str[i+1]))
            {
				// new = ft_content(new,flags,&str[i],i);
                // while (new[i] != NULL)
			    //     ft_putendl(new[i++]);
                ft_putstr("its a file  ");
				ft_putendl(str[i]);
				exit(0);
            }
            //its a directory
            else if (isDirectory(str[i]))
            {
                ft_putendl("hee");
                //ft_putendl(str[i]);
                 new = ft_content(new,flags,&str[i],i);
                 if(flags->flag_l == '1')
                    ft_file_info(new, str[i]);
                 if(flags->flag_l == '0')
                 {
			    	while (new[i] != NULL)
                        ft_putendl(new[i++]);
                 }
				exit(0);
            }
            //its junk ==== We don't want this =======
            else
            {
                ft_putstr("No such file or directory-- ");
				ft_putendl(str[i]);
                exit(0);
            }
        }
        // checking if str[i] a flag
        if (str[i][j] == '-' && ft_isalpha(str[i][j+1]))
        {
            ft_putendl(str[i + 1]);
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
