/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:57:03 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/14 09:44:35 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

t_ls	*ft_create_list(char *str, t_flags *flag)
{
	t_ls *node;
	struct stat checker;

	node = (t_ls*)malloc(sizeof(t_ls));
	if (node)
	{
		node->stat = (t_stat*)malloc(sizeof(t_stat)); 
		if(flag->flag_l == 1)
		{
			node->d_name = str;
			stat(node->d_name,&checker);
		}
		node->next = NULL;
	}
	return (node);
}
