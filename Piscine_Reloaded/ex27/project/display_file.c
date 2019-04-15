/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:52:03 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/04 10:33:18 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft.h"

void	display_file(char *filename)
{
	int		fd;
	int		ret;
	char	buf[4097];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	ret = read(fd, buf, 4097);
	ft_putstr(buf);
	close(fd);
}
