/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:50:10 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/26 14:11:33 by zmadi            ###   ########.fr       */
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
	char  flag_err;
	char  flag_active;
}			t_flags;
char		*flag_saver(char **str);
int 		array_counter(char **str);
int			count(char *dir);
void		ft_swap(char **new, int a, int b);
char		**ft_time_sort(char **new, char *dir);
char		*ft_path(char *filename, char *dir);//
int			ft_count_array(char **new);
char		**ft_reverse(char **new);
int			count();
void		ft_sort(char **new);
char		**ft_content(char **new, t_flags *flag, char **dir, int k);
void		ft_rights(struct stat mode);
void		handle_date(struct stat s);
void		group_rights(struct stat ptr);
int			usi_rights(char *ptr, char *dir);//
void		ft_file_info(char **ptr, char *dir);
int			check_flags(char **str, t_flags *flags);
int			ls_flag_error_handling(char *str);
int 		ft_opendir(char *str);
void		ft_space(int i, int b);
int		ft_count_nbr(int i);

#endif
