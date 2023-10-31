/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zorro_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:31 by skunert           #+#    #+#             */
/*   Updated: 2023/10/31 14:24:53 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	enemy_follow(t_game *g)
{
	if ((int)g->ds->sx > 0)
		g->zorro->x -= 1.4;
	if ((int)g->ds->sx < 0)
		g->zorro->x += 1.4;
	if ((int)g->ds->sy > 0)
		g->zorro->y -= 0.45;
	if ((int)g->ds->sy < 0)
		g->zorro->y += 0.45;
}

static mlx_texture_t	**load_all_pngs_zorro(int i)
{
	char			*str;
	char			*nbr;
	char			*tmp;
	mlx_texture_t	**animation;

	i = 0;
	str = "./textures/zorro/zorro-";
	animation = malloc(sizeof(mlx_texture_t *) * 18);
	if (animation == NULL)
		return (NULL);
	while (i < 17)
	{
		nbr = ft_itoa(i);
		tmp = ft_strjoin_free(nbr, ".png");
		nbr = ft_strjoin(str, tmp);
		animation[i] = mlx_load_png(nbr);
		if (!animation[i])
			return (free_prior_pngs(animation, i), free(animation), NULL);
		free(nbr);
		free(tmp);
		i++;
	}
	animation[i] = NULL;
	return (animation);
}

void	ft_get_location_zorro(char **map, t_zorro *zorr)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'Z')
			{
				zorr->x = j * DIMENS + 50;
				zorr->y = i * DIMENS + 50;
				return ;
			}
			j++;
		}
		i++;
	}
}

t_zorro	*zorro_init(char **map)
{
	t_zorro	*zorr;

	zorr = malloc(sizeof(t_zorro));
	if (zorr == NULL)
		return (NULL);
	zorr->animation = load_all_pngs_zorro(0);
	if (zorr->animation == NULL)
		return (free(zorr), NULL);
	zorr->i = 0;
	zorr->check = 0;
	zorr->x = 0;
	zorr->y = 0;
	zorr->z = 950;
	ft_get_location_zorro(map, zorr);
	return (zorr);
}
