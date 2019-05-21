/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:54:21 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/08 18:07:40 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void ***array)
{
	unsigned char	**tmp;
	int				i;

	tmp = (unsigned char**)*array;
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
}
