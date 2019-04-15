/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:16:01 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/10 15:36:01 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	int				i;
	int				sign;
	char			*str1;
	long long int	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	str1 = (char*)str;
	while (str1[i] == 32 || (str1[i] > 8 && str1[i] <= 13))
		i++;
	if (str1[i] == '-' || str1[i] == '+')
		if (str1[i++] == '-')
			sign = -1;
	while (str1[i] >= 48 && str1[i] <= 57)
	{
		nbr = nbr * 10 + str1[i] - 48;
		i++;
	}
	if (nbr < 0)
		return ((sign < 0) ? 0 : -1);
	return (sign * nbr);
}
