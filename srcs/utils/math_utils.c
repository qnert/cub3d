/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:46:47 by skunert           #+#    #+#             */
/*   Updated: 2023/10/20 18:47:00 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rad_to_degree(double rad)
{
	int	deg;

	deg = rad * (180 / M_PI);
	return (deg);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
