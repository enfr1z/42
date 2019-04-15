/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:03:33 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/02 18:11:09 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *str, char *str2)
{
	while (*str && *str2 && *str == *str2)
	{
		str++;
		str2++;
	}
	return (*str - *str2);
}

int		main(int ac, char **av)
{
	int		i;
	int		find;
	char	*swap;

	find = 1;
	while (find)
	{
		i = 0;
		find = 0;
		while (++i < ac - 1)
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				swap = av[i];
				av[i] = av[i + 1];
				av[i + 1] = swap;
				find = 1;
			}
	}
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
	}
	return (0);
}
