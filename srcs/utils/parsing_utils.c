/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:27:36 by skunert           #+#    #+#             */
/*   Updated: 2023/10/26 14:21:56 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

bool	is_component(char c)
{
	if (ft_strchr("01NSWED23LZ", c))
		return (true);
	return (false);
}

bool	is_valid_border(char c)
{
	if (!is_whitespace(c))
		if (c != '1')
			return (false);
	return (true);
}

void	ft_error_msg(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
}
