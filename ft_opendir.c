/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:07:57 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/14 09:41:25 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

int ft_opendir(char **str, t_flags *flag)
{
	t_ls *ptr;
    DIR *curdir;
    struct dirent *files;

	ptr = NULL;
	if (flag->flag_l == 1)
	{
		ptr = ft_create_list(str[0], flag);
		//ft_file_info(ptr->d_name, flag);
		ptr->d_name = ft_strdup("\nhello\n");
		//curdir = opendir(ptr->d_name);
		//if (!curdir)
		//{
		//	perror(EXIT_FAILURE);
		//	exit(1);
		//}
	//	while ((files = readdir(curdir)) != NULL)
	//	{
	//		ft_putstr(files->d_name);
	//		ft_putchar('\t');
	//	}
	//	closedir(curdir);
		ft_putstr(ptr->d_name);
	}
	   	return (1);
}

int main(int ac, char **av)
{
	(void)ac;

	t_flags *tmp = malloc(sizeof(t_flags));
	tmp->flag_l = 1;

	ft_opendir(av,tmp);
	return 0;
}
