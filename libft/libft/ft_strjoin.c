/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:07:42 by skunert           #+#    #+#             */
/*   Updated: 2023/11/01 15:59:08 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*str_j;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	i = 0;
	j = 0;
	str_j = ft_calloc(len + 1, sizeof(char));
	if (!str_j)
		return (NULL);
	while (s1[i] != '\0')
	{
		str_j[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str_j[i + j] = s2[j];
		j++;
	}
	return (str_j);
}
