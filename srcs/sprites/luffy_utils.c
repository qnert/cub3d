/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luffy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:31 by skunert           #+#    #+#             */
/*   Updated: 2023/10/31 14:15:06 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_prior_pngs(mlx_texture_t **animation, int n)
{
	int	i;

	i = 0;
	while (i < n)
		mlx_delete_texture(animation[i]);
	free(animation);
}

mlx_texture_t	**load_all_pngs(int i)
{
	char			*str;
	char			*nbr;
	char			*tmp;
	mlx_texture_t	**animation;

	i = 0;
	str = "./textures/luffy/luffy-";
	animation = malloc(sizeof(mlx_texture_t *) * 73);
	if (animation == NULL)
		return (NULL);
	while (i < 72)
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
	if (luf == NULL)
		return (NULL);
	luf->animation = load_all_pngs(0);
	if (luf->animation == NULL)
		return (free(luf), NULL);
	luf->i = 0;
	luf->check = 0;
	luf->x = 0;
	luf->y = 0;
	luf->z = 550;
	ft_get_location_luffy(map, luf);
	return (luf);
}
