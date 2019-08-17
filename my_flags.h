/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:50:10 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/17 13:00:51 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MY_FLAGS_H

# define MY_FLAGS_H

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

typedef struct stat t_stat;
typedef struct  s_flags
{
	char flag_l;
	char  flag_a;
	char  flag_R;
	char  flag_r;
	char  flag_t;
	char  flag_o;
	char  flag_n;
	char  flag_g;

}				t_flags;

typedef struct s_ls
{
	t_stat				*stat;
	char				*d_name;
	struct	s_ls		*next;
}						t_ls;

void		ft_rights(int mode);
void		handle_date(t_ls *ptr);
void		group_rights(struct stat *ptr, t_flags *flag);
int			usi_rights(t_ls *put, t_flags *flag);
void		ft_file_info(char *ptr, t_flags *flag);
int			check_flags(char *str, t_flags *flags);
int 		ls_error_handling(char *str, t_flags *flag);
int 		ft_opendir(char **str, t_flags *flag);
t_ls    	*ft_create_list(char *d_name, t_flags *flag);

#endif
