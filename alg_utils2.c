#include "alg_header.h"

void	distance(t_player_set *player)
{
	if (player->calc.side == 0)
		player->calc.perpWallDist = (player->calc.sideDistX - player->calc.deltaDistX);
	else
		player->calc.perpWallDist = (player->calc.sideDistY - player->calc.deltaDistY);
	player->draw.lineHeight = (int)(height / player->calc.perpWallDist);
	player->draw.drawStart = -1 * player->draw.lineHeight / 2 + height / 2;
	if (player->draw.drawStart < 0)
		player->draw.drawStart = 0;
	player->draw.drawEnd = player->draw.lineHeight / 2 + height / 2;
	if (player->draw.drawEnd >= height)
		player->draw.drawEnd = height - 1;
}