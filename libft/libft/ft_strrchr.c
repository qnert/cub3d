/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:13:18 by skunert           #+#    #+#             */
/*   Updated: 2023/03/20 16:51:55 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen((char *)str);
	tmp = NULL;
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		if (str[i] == (char)c)
		{
			tmp = (char *) str + i;
		}
		i++;
	}
	if (str[i] == (char)c)
		tmp = (char *) str + i;
	if (tmp == NULL)
	{
		return (NULL);
	}
	return (tmp);
}
