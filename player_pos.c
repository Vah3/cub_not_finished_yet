/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:04:07 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/17 13:07:26 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

void	set_dir_values(t_player_set *player, double v1, double v2)
{
	player->dir_x = v1;
	player->dir_y = v2;
}

void	set_plane_values(t_player_set *player, double v1, double v2)
{
	player->plane_x = v1;
	player->plane_y = v2;
}

void	init_player(t_player_set *player)
{
	if (player->face_to == 'E')
	{
		set_dir_values(player, 1, 0);
		set_plane_values(player, 0, 0.66);
	}
	else if (player->face_to == 'W')
	{
		set_dir_values(player, -1, 0);
		set_plane_values(player, 0, -0.66);
	}
	else if (player->face_to == 'N')
	{
		set_dir_values(player, 0, -1);
		set_plane_values(player, 0.66, 0);
	}
	else if (player->face_to == 'S')
	{
		set_dir_values(player, 0, 1);
		set_plane_values(player, -0.66, 0);
	}
}
