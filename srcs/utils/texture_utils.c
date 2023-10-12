/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:07:50 by skunert           #+#    #+#             */
/*   Updated: 2023/10/12 14:03:46 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_pixels_img(mlx_image_t *img, int max_x, int max_y, u_int32_t c)
{
	int	x;
	int	y;

	x = 0;
	while (x < max_x)
	{
		y = 0;
		while (y < max_y)
		{
			if (x == 0 || x == max_x - 1)
				mlx_put_pixel(img, x, y, 0x0000FF);
			else if (y == 0 || y == max_y - 1)
				mlx_put_pixel(img, x, y, 0x0000FF);
			else
				mlx_put_pixel(img, x, y, c);
			y++;
		}
		x++;
	}
}
