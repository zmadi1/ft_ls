/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:43:19 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/23 14:42:46 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

char	*ft_path(char *filename, char *dir)
{
	// int i;
	// size_t len;

	// i = 0;
	// len = ft_strlen(filename)
	char *ret;
	ret = NULL;
	ret = ft_strjoin(dir, "/");//memory leak
	ret = ft_strjoin(ret, filename);
	return (ret);
}
