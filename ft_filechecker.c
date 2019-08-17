/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filechecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 08:38:13 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/17 13:19:00 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "my_flags.h"


void	ft_rights(int mode)
{
	char *i;
 
	if (!(i = malloc(sizeof(i)* 10)))
		return ;
	i[0] = ((mode & S_IRUSR) != 0) ? 'r' : '-';
	i[1] = ((mode & S_IWUSR) != 0) ? 'w' : '-';
	i[2] = ((mode & S_IXUSR) != 0) ? 'w' : '-';
	i[3] = ((mode & S_IRGRP) != 0) ? 'w' : '-';
	i[4] = ((mode & S_IWGRP) != 0) ? 'w' : '-';
	i[5] = ((mode & S_IXGRP) != 0) ? 'w' : '-';
	i[6] = ((mode & S_IROTH) != 0) ? 'w' : '-';
	i[7] = ((mode & S_IWOTH) != 0) ? 'w' : '-';
	i[8] = ((mode & S_IXOTH) != 0) ? 'w' : '-';
	i[9] = '\0';
	ft_putstr(i);
	free(i);
}

void	handle_date(t_ls *ptr)
{
	char **date;
	struct stat	s;


	date = ft_strsplit(ctime(&s.st_mtimespec.tv_sec), ' ');
	ft_putstr(date[1]);
	ft_putchar(' ');
	!date[2][1] ? ft_putchar(' ') : 0;
	ft_putchar(' ');
	ft_putstr(date[2]);
	ft_putchar(' ');
	date[3][5] = '\0';
	date[4][4] = '\0';
	ft_putstr(date[3]);
	free(date);
}

void	group_rights(struct stat *ptr, t_flags *flag)
{
	struct group *grp;

	grp = getgrgid(ptr->st_gid);
	if( grp && grp->gr_name)
		ft_putstr(grp->gr_name);
	ft_putchar(' ');
	if (S_ISBLK (ptr->st_mode) || S_ISCHR(ptr->st_mode))
	{
		ft_putchar(' ');
		ft_putnbr(major(ptr->st_rdev));
		ft_putstr(", ");
		ft_putnbr(minor(ptr->st_rdev));
	}
	ft_putchar(' ');
}

int usi_rights(t_ls *ptr, t_flags *flag)
{
	struct stat *user;
	struct passwd *parent;

	user = (struct stat*)malloc(sizeof(struct stat));
	ft_putchar(' ');
	if(lstat(ptr->d_name, user) != 0)
		return (errno);
	ft_putnbr(user->st_nlink);
	ft_putchar(' ');
	parent = getpwuid(user->st_uid);
	if (parent && parent->pw_name)
		ft_putstr(parent->pw_name);
	ft_putchar(' ');
	group_rights(user,flag);
	handle_date(ptr);
	free(user);
	return (0);

}

void ft_file_info(char *ptr,t_flags *flag)
{
	struct stat checker;

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
	ft_rights(checker.st_mode);

	usi_rights(ptr,flag);
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	(void)ac;

	t_flags *tmp = NULL;
	while(av[i])
	{
		ft_file_info(av[i],tmp);
		i++;
	}
	return 0;
}
