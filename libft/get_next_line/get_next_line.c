/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:40:12 by skunert           #+#    #+#             */
/*   Updated: 2023/04/03 16:02:25 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_bytes(int fd, char *line_str)
{
	char	*buff;
	int		read_value;

	if (line_str == NULL)
		line_str = ft_calloc(1, 1);
	if (line_str == NULL)
		return (NULL);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	read_value = 1;
	while (read_value > 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		read_value = read(fd, buff, BUFFER_SIZE);
		if (read_value == -1)
			return (free(buff), free(line_str), NULL);
		line_str = ft_strjoin_free(line_str, buff);
		if (ft_strchr(line_str, '\n') != 0)
			break ;
	}
	return (free (buff), line_str);
}

char	*ft_str_trim_line(char *line_str)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (line_str == NULL || ft_strlen(line_str) == 0)
		return (NULL);
	while (line_str[i] != '\n' && line_str[i])
		i++;
	if (ft_strchr(line_str, '\n'))
		i++;
	buff = ft_calloc(i + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (line_str[j] != '\n' && line_str[j])
	{
		buff[j] = line_str[j];
		j++;
	}
	if (line_str[j] == '\n')
		buff[j] = '\n';
	return (buff);
}

char	*ft_str_trim_front(char *line_str)
{
	char	*new_line_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (line_str == NULL)
		return (NULL);
	while (line_str[i] != '\n' && line_str[i])
		i++;
	if (line_str[i] == '\0')
		return (free (line_str), NULL);
	new_line_str = ft_calloc(ft_strlen(line_str) - i + 1, sizeof(char));
	if (new_line_str == NULL)
		return (NULL);
	if (ft_strchr(line_str, '\n'))
		i++;
	while (line_str[j + i] != '\0')
	{
		new_line_str[j] = line_str[j + i];
		j++;
	}
	free (line_str);
	return (new_line_str);
}

char	*get_next_line(int fd)
{
	static char	*line_str;
	char		*ret_buff;

	ret_buff = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line_str = read_bytes(fd, line_str);
	ret_buff = ft_str_trim_line(line_str);
	line_str = ft_str_trim_front(line_str);
	return (ret_buff);
}
