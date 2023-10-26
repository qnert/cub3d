/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luffy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:31 by skunert           #+#    #+#             */
/*   Updated: 2023/10/26 13:23:57 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

mlx_texture_t	**load_all_pngs(int i)
{
	char			*str;
	char			*nbr;
	char			*tmp;
	mlx_texture_t	**animation;

	i = 0;
	str = "./textures/luffy/luffy-";
	animation = malloc(sizeof(mlx_texture_t *) * 73);
	while (i < 72)
	{
		nbr = ft_itoa(i);
		tmp = ft_strjoin_free(nbr, ".png");
		nbr = ft_strjoin(str, tmp);
		animation[i] = mlx_load_png(nbr);
		free(nbr);
		free(tmp);
		i++;
	}
	animation[i] = NULL;
	return (animation);
}

void	ft_get_location_luffy(char **map, t_luffy *luf)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'L')
			{
				luf->x = j * DIMENS + 20;
				luf->y = i * DIMENS + 20;
				return ;
			}
			j++;
		}
		i++;
	}
}

t_luffy	*luffy_init(char **map)
{
	t_luffy	*luf;

	luf = malloc(sizeof(t_luffy));
	luf->animation = load_all_pngs(0);
	luf->i = 0;
	luf->check = 0;
	luf->x = 0;
	luf->y = 0;
	luf->z = 550;
	ft_get_location_luffy(map, luf);
	return (luf);
}
