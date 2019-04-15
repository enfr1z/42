/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:16:22 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/06 12:38:23 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int r;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	r = 2;
	while (r * r <= nb)
	{
		if (r * r == nb)
			return (r);
		r++;
	}
	return (0);
}