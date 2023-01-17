/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:09:08 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/17 17:12:25 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

int	set_true(int key, void *param)
{
	t_player_set	*player;

	player = (t_player_set *) param;
	if (key == 124)
		rotate(player, ROT_SPEED);
	else if (key == 123)
		rotate(player, -ROT_SPEED);
	else if (key == 13)
		move_up(player);
	else if (key == 1)
		move_down(player);
	else if (key == 0)
		move_left(player);
	else if (key == 2)
		move_right(player);
	if (key == 124 || key == 123 || key == 13
		|| key == 1 || key == 0 || key == 2)
		ft_ray_cast(player);
	return (0);
}
