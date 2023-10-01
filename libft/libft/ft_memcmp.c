/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:40:40 by skunert           #+#    #+#             */
/*   Updated: 2023/03/20 16:25:55 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;
	unsigned int	i;

	ptr_str1 = (unsigned char *) str1;
	ptr_str2 = (unsigned char *) str2;
	i = 0;
	while (i < n)
	{
		if (ptr_str1[i] != ptr_str2[i])
		{
			return (ptr_str1[i] - ptr_str2[i]);
		}
		i++;
	}
	return (0);
}
