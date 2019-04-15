/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:27:41 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/02 15:46:49 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int len;
	int i;

	i = 0;
	if (min >= max)
		return (NULL);
	len = max - min;
	tab = (int*)malloc(sizeof(int) * len);
	while (min < max)
	{
		tab[i] = min++;
		i++;
	}
	i = 0;
	return (tab);
}
