/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrirte_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 22:57:05 by amtan             #+#    #+#             */
/*   Updated: 2026/03/17 22:58:19 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <errno.h>
#include <unistd.h>

int	ft_write_all(int fd, const void *buf, size_t len)
{
	size_t	off;
	ssize_t	wr;

	off = 0;
	while (off < len)
	{
		wr = write(fd, (const char *)buf + off, len - off);
		if (wr < 0)
		{
			if (errno == EINTR)
				continue ;
			return (1);
		}
		if (wr == 0)
			return (1);
		off += (size_t)wr;
	}
	return (0);
}
