/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:40:21 by skunert           #+#    #+#             */
/*   Updated: 2023/04/06 12:43:28 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Nummer ausgeben
void	ft_putnbr(long long n, int *ret_len)
{
	char			c;

	if (n < 0)
	{
		ft_putchar('-', ret_len);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, ret_len);
		ft_putnbr(n % 10, ret_len);
	}
	else
	{
		c = n + '0';
		ft_putchar(c, ret_len);
	}
}

//Hexadezimalzahl mit kleinen Buchstaben
void	ft_putnbr_hexa_lower(long long n, int *ret_len)
{
	char	*s;
	char	tmp_s[20];
	int		i;
	int		tmp;

	if (n < 0)
		n = 4294967296 + n;
	s = "0123456789abcdef";
	i = 0;
	if (n == 0)
		ft_putchar('0', ret_len);
	while (n != 0)
	{
		tmp = n % 16;
		n = n / 16;
		tmp_s[i] = s[tmp];
		i++;
	}
	while (i--)
		ft_putchar(tmp_s[i], ret_len);
}

//Hexadezimalzahl mit großen Buchstaben
void	ft_putnbr_hexa_upper(long long n, int *ret_len)
{
	char	*s;
	char	tmp_s[20];
	int		i;
	int		tmp;

	if (n < 0)
		n = 4294967296 + n;
	if (n == 0)
		ft_putchar('0', ret_len);
	s = "0123456789ABCDEF";
	i = 0;
	while (n != 0)
	{
		tmp = n % 16;
		n = n / 16;
		tmp_s[i] = s[tmp];
		i++;
	}
	while (i--)
		ft_putchar(tmp_s[i], ret_len);
}

void	ft_putnbr_adress_hexa(unsigned long long n, int *ret_len)
{
	char	*s;
	char	tmp_s[30];
	int		i;
	int		tmp;

	s = "0123456789abcdef";
	i = 0;
	if (n == 0)
		ft_putchar('0', ret_len);
	while (n != 0)
	{
		tmp = n % 16;
		n = n / 16;
		tmp_s[i] = s[tmp];
		i++;
	}
	while (i--)
		ft_putchar(tmp_s[i], ret_len);
}

void	ft_putadress(void *ptr, int *ret_len)
{
	unsigned long	converted_ptr;

	ft_putstr("0x", ret_len);
	if (ptr == NULL)
		ft_putstr("0", ret_len);
	else
	{
		converted_ptr = (unsigned long) ptr;
		ft_putnbr_adress_hexa(converted_ptr, ret_len);
	}
}
