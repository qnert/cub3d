/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:26:28 by skunert           #+#    #+#             */
/*   Updated: 2023/05/04 19:05:22 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(const char *s1, const char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*str_j;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	str_j = ft_calloc(len + 1, sizeof(char));
	if (str_j == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str_j[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		str_j[i + j] = s2[j];
		j++;
	}
	free((void *) s1);
	return (str_j);
}
