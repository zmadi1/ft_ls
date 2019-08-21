/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:50:10 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/21 12:06:07 by zmadi            ###   ########.fr       */
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

}			t_flags;
void		ft_swap(char **new, int a, int b);
char		**ft_time_sort(char **new);
char		*ft_path(char *str);
int			ft_count_array(char **new);
char		**ft_reverse(char **new);
int			count();
void		ft_sort(char **new);
char		**ft_content(char **new, t_flags *flag);
void		ft_rights(struct stat mode);
void		handle_date(struct stat s);
void		group_rights(struct stat ptr);
int			usi_rights(char *ptr);
void		ft_file_info(char **ptr);
int			check_flags(char *str, t_flags *flags);
int			ls_flag_error_handling(char *str, t_flags *flag);
int 		ft_opendir(char *str);
void		ft_space(int i, int b);
int		ft_count_nbr(int i);

#endif
