/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:18:30 by vsanta            #+#    #+#             */
/*   Updated: 2019/04/21 14:11:00 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoastr(int n, int len, int i)
{
	int		del;
	char	*str;

	del = ft_delint(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (i < len)
	{
		str[i] = n / del + 48;
		n = n % del;
		del = del / 10;
		i++;
	}
	str[i] = 0;
	return (str);
}

char			*ft_itoa(int n)
{
	int len;
	int i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_digitcount(n);
	i = 0;
	if (n < 0)
	{
		i = 1;
		len = len + 1;
	}
	return (ft_itoastr(n, len, i));
}
