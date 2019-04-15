/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:09:47 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/15 13:19:44 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_count_words(const char *s, char c)
{
	int wrd;
	int flag;

	flag = 0;
	wrd = 0;
	while (*s)
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			wrd++;
		}
		s++;
	}
	return (wrd);
}

static char		**ft_del(char **tab)
{
	if (tab)
	{
		while (*tab)
		{
			free(*tab);
			*tab = NULL;
			tab++;
		}
		free(tab);
		tab = NULL;
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	start;
	char	**tab;

	if ((s == 0) || (c == 0))
		return (NULL);
	len = ft_count_words(s, c);
	if ((tab = ft_memalloc((sizeof(char *) * (len + 1)))) == NULL)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < len)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if ((tab[j] = ft_strsub(s, start, i++ - start)) == NULL)
			return (ft_del(tab));
	}
	tab[j] = NULL;
	return (tab);
}
