/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:22:31 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/06 19:47:38 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				return (1);
			i++;
		}
	}
	return (0);
}
