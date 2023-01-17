/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:08:47 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/17 17:17:28 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

extern int	g_map[24][24];

void	dda_find_wall(t_player_set *player)
{
	player->calc.hit = 0;
	while (player->calc.hit == 0)
	{
		if (player->calc.sidedistx < player->calc.sidedisty)
		{
			player->calc.sidedistx += player->calc.deltadistx;
			player->calc.mapx += player->calc.stepx;
			player->calc.side = 0;
		}
		else
		{
			player->calc.sidedisty += player->calc.deltadisty;
			player->calc.mapy += player->calc.stepy;
			player->calc.side = 1;
		}
		if (g_map[player->calc.mapx][player->calc.mapy] > 0)
			player->calc.hit = 1;
	}
}

static void	token_distance_and_side_util(t_player_set *player)
{
	if (player->calc.ray_dir_y < 0)
	{
		player->calc.stepy = -1;
		player->calc.sidedisty = (player->pos_y - player->calc.mapy) \
		* player->calc.deltadisty;
	}
	else
	{
		player->calc.stepy = 1;
		player->calc.sidedisty = (player->calc.mapy + 1.0 - player->pos_y) \
		* player->calc.deltadisty;
	}
}

void	token_distance_and_side(t_player_set *player)
{
	player->calc.mapx = (int)player->pos_x;
	player->calc.mapy = (int)player->pos_y;
	player->calc.deltadistx = fabs(1 / player->calc.ray_dir_x);
	player->calc.deltadisty = fabs(1 / player->calc.ray_dir_y);
	if (player->calc.ray_dir_x < 0)
	{
		player->calc.stepx = -1;
		player->calc.sidedistx = (player->pos_x - player->calc.mapx) \
		* player->calc.deltadistx;
	}
	else
	{
		player->calc.stepx = 1;
		player->calc.sidedistx = (player->calc.mapx + 1 - player->pos_x) \
		* player->calc.deltadistx;
	}
	token_distance_and_side_util(player);
}

void	pos_dir_camera(t_player_set *player, int x)
{
	player->calc.camerax = 2 * x / (double)WIDTH - 1;
	player->calc.ray_dir_x = player->dir_x + player->plane_x \
	* player->calc.camerax;
	player->calc.ray_dir_y = player->dir_y + player->plane_y \
	* player->calc.camerax;
}

void	ft_ray_cast(t_player_set *player)
{
	int	for_each_pixel;

	for_each_pixel = 0;
	while (for_each_pixel < WIDTH)
	{
		pos_dir_camera(player, for_each_pixel);
		token_distance_and_side(player);
		dda_find_wall(player);
		distance(player);
		drawing_wall(player, for_each_pixel);
		for_each_pixel++;
	}
	mlx_put_image_to_window(player->d_mlx.mlx, player->d_mlx.win,
		player->gen_img.image, 0, 0);
}
