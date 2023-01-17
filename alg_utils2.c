/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:50 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/17 17:11:15 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

void	distance(t_player_set *player)
{
	if (player->calc.side == 0)
		player->calc.perpwalldist
			= (player->calc.sidedistx - player->calc.deltadistx);
	else
		player->calc.perpwalldist
			= (player->calc.sidedisty - player->calc.deltadisty);
	player->draw.lineheight = (int)(HEIGHT / player->calc.perpwalldist);
	player->draw.drawstart = -1 * player->draw.lineheight / 2 + HEIGHT / 2;
	if (player->draw.drawstart < 0)
		player->draw.drawstart = 0;
	player->draw.drawend = player->draw.lineheight / 2 + HEIGHT / 2;
	if (player->draw.drawend >= HEIGHT)
		player->draw.drawend = HEIGHT - 1;
}
