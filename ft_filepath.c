/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:43:19 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/17 17:25:37 by zmadi            ###   ########.fr       */
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
	char *ptr = NULL;
	ret = NULL;
	ptr = ft_strjoin(dir, "/");
	
	ret = ft_strjoin(ptr, filename);
	ft_strdel(&ptr);
	// ft_putendl("in path function");
	//  ft_putendl(ret);
	//  	 ft_putendl("ola");
	// 	  	 ft_putendl(filename);
	//  exit(0);
	return (ret);
}
