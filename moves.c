/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:11:40 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/17 17:18:08 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

extern int	g_map[24][24];

void	rotate(t_player_set *player, double rot_)
{
	double	old;

	old = player->dir_x;
	player->dir_x = old * cos(rot_) - player->dir_y * sin(rot_);
	player->dir_y = old * sin(rot_) + player->dir_y * cos(rot_);
	old = player->plane_x;
	player->plane_x = old * cos(rot_) - player->plane_y * sin(rot_);
	player->plane_y = old * sin(rot_) + player->plane_y * cos(rot_);
}

void	move_left(t_player_set *player)
{
	int	y;
	int	x;

	x = (int)(player->pos_x - player->plane_x * (MOVE_SPEED + 0.1));
	y = (int)player->pos_y;
	if (g_map[x][y] == 0)
		player->pos_x -= player->plane_x * (MOVE_SPEED);
	y = (int)(player->pos_y - player->plane_y * (MOVE_SPEED + 0.1));
	x = (int)player->pos_x;
	if (g_map[x][y] == 0)
		player->pos_y -= player->plane_y * (MOVE_SPEED);
}

void	move_right(t_player_set *player)
{
	int	y;
	int	x;

	x = (int)(player->pos_x + player->plane_x * (MOVE_SPEED + 0.1));
	y = (int)player->pos_y;
	if (g_map[x][y] == 0)
		player->pos_x += player->plane_x * (MOVE_SPEED);
	y = (int)(player->pos_y + player->plane_y * (MOVE_SPEED + 0.1));
	x = (int)player->pos_x;
	if (g_map[x][y] == 0)
		player->pos_y += player->plane_y * (MOVE_SPEED);
}

void	move_down(t_player_set *player)
{
	int	y;
	int	x;

	x = (int)(player->pos_x - player->dir_x * (MOVE_SPEED + 0.1));
	y = (int)player->pos_y;
	if (g_map[x][y] == 0)
		player->pos_x -= player->dir_x * (MOVE_SPEED);
	y = (int)(player->pos_y - player->dir_y * (MOVE_SPEED + 0.1));
	x = (int)player->pos_x;
	if (g_map[x][y] == 0)
		player->pos_y -= player->dir_y * (MOVE_SPEED);
}

void	move_up(t_player_set *player)
{
	int	y;
	int	x;

	x = (int)(player->pos_x + player->dir_x * (MOVE_SPEED + 0.1));
	y = (int)player->pos_y;
	if (g_map[x][y] == 0)
		player->pos_x += player->dir_x * (MOVE_SPEED);
	y = (int)(player->pos_y + player->dir_y * (MOVE_SPEED + 0.1));
	x = (int)player->pos_x;
	if (g_map[x][y] == 0)
		player->pos_y += player->dir_y * (MOVE_SPEED);
}
