/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filechecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 08:38:13 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/21 12:05:39 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "my_flags.h"

/*void	ft_space(int i, int b)
{
	int		a;

	a = 0;
	while (a < (b - i))
	{
		ft_putchar(' ');
		a++;
	}
}

int		ft_count_nbr(int i)
{
	int		a;

	a = 0;
	while (i /= 10)
		a++;
	return (a);
}
*/
void	ft_rights(struct stat mode)
{
	char *i;
 
	if (!(i = malloc(sizeof(i)* 10)))
		return ;
	i[0] = (S_IRUSR & mode.st_mode) ? 'r' : '-';
	i[1] = (S_IWUSR & mode.st_mode) ? 'w' : '-';
	i[2] = (S_IXUSR & mode.st_mode) ? 'x' : '-';
	i[3] = (S_IRGRP & mode.st_mode) ? 'r' : '-';
	i[4] = (S_IWGRP & mode.st_mode) ? 'w' : '-';
	i[5] = (S_IXGRP & mode.st_mode) ? 'x' : '-';
	i[6] = (S_IROTH & mode.st_mode) ? 'r' : '-';
	i[7] = (S_IWOTH & mode.st_mode) ? 'w' : '-';
	i[8] = (S_IXOTH & mode.st_mode) ? 'x' : '-';
	i[9] = '\0';
	ft_putstr(i);
	free(i);
}

void	handle_date(struct stat s)
{
	char **date;

	date = ft_strsplit(ctime(&s.st_mtimespec.tv_sec), ' ');
	ft_putstr(date[1]);
	ft_putstr(" ");
	!date[2][1] ? ft_putchar(' ') : 0;
	ft_putstr(date[2]);
	ft_putstr(" ");
	date[3][5] = '\0';
	date[4][4] = '\0';
	ft_putstr(date[3]);
	free(date);
}

void	group_rights(struct stat ptr)
{
	struct group *grp;

	grp = getgrgid(ptr.st_gid);
	ft_putstr(grp->gr_name);
	ft_space(ft_count_nbr(ptr.st_size), 6);
	ft_putnbr(ptr.st_size);
	ft_putchar(' ');
}

int usi_rights(char	*ptr)
{
	struct stat user;
	struct passwd *parent;

	lstat(ft_path(ptr),&user);
	ft_space(ft_count_nbr(user.st_nlink), 4);
	ft_putnbr(user.st_nlink);
	ft_putchar(' ');
	parent = getpwuid(user.st_uid);
	ft_putstr(parent->pw_name);
	ft_putchar(' ');
	
	group_rights(user);
	handle_date(user);
	ft_putchar(' ');
	return (0);

}

void ft_file_info(char **ptr)
{
	struct stat checker;
	int			i;

	i = 0;
	while (ptr[i] != NULL)
	{
		stat(ft_path(ptr[i]), &checker);
		if (S_ISBLK(checker.st_mode))
			ft_putchar('b');
		else if(S_ISCHR(checker.st_mode))
			ft_putchar('c');
		else if (S_ISDIR(checker.st_mode))
			ft_putchar('d');
		else if (S_ISFIFO(checker.st_mode))
			ft_putchar('p');
		else if (S_ISREG(checker.st_mode))
			ft_putchar('-');
		else if (S_ISLNK(checker.st_mode))
			ft_putchar('l');
		else if (S_ISSOCK(checker.st_mode))
			ft_putchar('s');
		else
			ft_putchar('?');
		ft_rights(checker);
		usi_rights(ptr[i]);
		ft_putendl(ptr[i]);
		i++;
	}

}
