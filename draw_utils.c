/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:21 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/17 17:08:17 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

static char	*which_image_util(t_player_set *player, int which, int x)
{
	int		y;
	char	*c;

	c = NULL;
	if (which == 3)
	{
		y = (int)floor(player->img.img3.y);
		c = player->img.img3.addr + (y * player->img.img3.size_line \
			+ x * (player->img.img3.bpp / 8));
		player->img.img3.y += player->img.img3.step;
	}
	else if (which == 4)
	{
		y = (int)floor(player->img.img4.y);
		c = player->img.img4.addr + (y * player->img.img4.size_line \
			+ x * (player->img.img4.bpp / 8));
		player->img.img4.y += player->img.img4.step;
	}
	return (c);
}

static char	*which_image(t_player_set *player, int which, int x)
{
	int		y;
	char	*c;

	c = NULL;
	if (which == 1)
	{
		y = (int)floor(player->img.img1.y);
		c = player->img.img1.addr + (y * player->img.img1.size_line \
			+ x * (player->img.img1.bpp / 8));
		player->img.img1.y += player->img.img1.step;
	}
	else if (which == 2)
	{
		y = (int)floor(player->img.img2.y);
		c = player->img.img2.addr + (y * player->img.img2.size_line \
			+ x * (player->img.img2.bpp / 8));
		player->img.img2.y += player->img.img2.step;
	}
	else
		c = which_image_util(player, which, x);
	return (c);
}

static void	set_color(t_player_set *player, char *color, int which)
{
	double	wallx;
	int		x;
	int		y;
	char	*c;

	c = NULL;
	if (player->calc.side == 1)
		wallx = player->pos_x + player->calc.perpwalldist \
		* player->calc.ray_dir_x;
	else if (player->calc.side == 0)
		wallx = player->pos_y + player->calc.perpwalldist \
		* player->calc.ray_dir_y;
	wallx -= floor(wallx);
	wallx = player->img.img1.img_len * wallx;
	wallx = floor(wallx);
	x = (int)wallx;
	c = which_image(player, which, x);
	*(int *)color = *(int *)c;
}

void	find_side(t_player_set *player, char *color)
{
	double	wallx;
	char	*c;

	if (player->calc.side == 1 && player->calc.ray_dir_y < 0)
		set_color(player, color, 1);
	else if (player->calc.side == 1 && player->calc.ray_dir_y > 0)
		set_color(player, color, 2);
	else if (player->calc.side == 0 && player->calc.ray_dir_x > 0)
		set_color(player, color, 3);
	else if (player->calc.side == 0 && player->calc.ray_dir_x < 0)
		set_color(player, color, 4);
	else
		*(int *)color = 0xe9e9e9;
}
