/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:41:58 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# ifndef FILE_READ_SIZE
#  define FILE_READ_SIZE 256
# endif

# include <stddef.h>

int		read_file(char *filename);
int		check_file_size(const char *filename);
void	read_file_from_nbyte(const char *filename, int start);
size_t	file_count_lines(char *filename);

#endif