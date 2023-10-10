/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:20:03 by skunert           #+#    #+#             */
/*   Updated: 2023/10/10 17:19:08 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t max_dstsize)
{
	unsigned int	i;
	unsigned int	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	if (max_dstsize <= dst_len)
		return (max_dstsize + ft_strlen((char *)src));
	while (src[i] != '\0' && dst_len + i < max_dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (ft_strlen(dst) + ft_strlen((char *)src + i));
}
