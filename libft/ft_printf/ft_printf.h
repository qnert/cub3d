/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:34:29 by skunert           #+#    #+#             */
/*   Updated: 2023/04/05 14:49:57 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

void	ft_check_specifiers(char c, va_list ptr, int *ret_len);
int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *ret_len);
void	ft_putstr(char *s, int *ret_len);
void	ft_putpercent(int *ret_len);
void	ft_putnbr(long long n, int *ret_len);
void	ft_putnbr_hexa_lower(long long n, int *ret_len);
void	ft_putnbr_hexa_upper(long long n, int *ret_len);
void	ft_putadress(void *ptr, int *ret_len);

#endif