/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:40:30 by skunert           #+#    #+#             */
/*   Updated: 2023/04/05 11:13:00 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//ein Character
void	ft_putchar(char c, int *ret_len)
{
	(*ret_len)++;
	write(1, &c, 1);
}

//ein String
void	ft_putstr(char *s, int *ret_len)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", ret_len);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i], ret_len);
		i++;
	}
}

//ein Prozentzeichen
void	ft_putpercent(int *ret_len)
{
	(*ret_len)++;
	write(1, "%%", 1);
}
