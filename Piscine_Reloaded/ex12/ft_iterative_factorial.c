/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:35:10 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/02 12:05:22 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int n;

	n = nb;
	if (nb > 0 && nb <= 12)
	{
		while (nb > 1)
		{
			n = n * (nb - 1);
			nb--;
		}
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
	return (n);
}
