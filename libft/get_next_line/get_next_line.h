/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:26:33 by skunert           #+#    #+#             */
/*   Updated: 2023/05/04 19:04:53 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libs.h"

size_t	ft_strlen(const char *s);
void	ft_bzero(void *dst, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin_free(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*read_bytes(int fd, char *line_str);
char	*ft_str_trim_line(char *line_str);
char	*ft_str_trim_front(char *line_str);
char	*get_next_line(int fd);

#endif
