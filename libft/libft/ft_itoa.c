/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:27:33 by skunert           #+#    #+#             */
/*   Updated: 2023/03/24 14:27:43 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	if (n < 10)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	top_up_array(int i, int n, int ten_pow, char *nbr)
{
	int	len;

	len = nbr_len(n);
	if (n < 0)
	{
		nbr[i] = '-';
		n *= -1;
		i++;
		len++;
	}
	while (i < len)
	{
		nbr[i] = n / ten_pow + '0';
		n = n - ((n / ten_pow) * ten_pow);
		ten_pow = ten_pow / 10;
		i++;
	}
}

char	*ft_itoa(int n)
{
	int				i;
	int				ten_pow;
	char			*nbr;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = 0;
	ten_pow = 1;
	if (n < 0)
		nbr = ft_calloc(nbr_len(n) + 2, sizeof(char));
	else
		nbr = ft_calloc(nbr_len(n) + 1, sizeof(char));
	if (!nbr)
		return (NULL);
	while (i != nbr_len(n) - 1)
	{
		ten_pow *= 10;
		i++;
	}
	i = 0;
	top_up_array(i, n, ten_pow, nbr);
	return (nbr);
}
