/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:53:18 by skunert           #+#    #+#             */
/*   Updated: 2023/03/25 16:49:16 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// needs to segfault so check no check for str == NULL because strlen SEGFAULT
char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)str);
	while (i < len)
	{
		if (str[i] == (char)c)
			return ((char *) str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *) str + i);
	return (0);
}
