#include "alg_header.h"

extern int map[24][24];

void	rotate(t_player_set *player,double rot_)
{
	double old;

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

	x = (int)(player->pos_x  - player->plane_x * (move_speed + 0.1));
	y = (int)player->pos_y;
	if (map[x][y] == 0)
		player->pos_x -= player->plane_x * (move_speed  );
	y = (int)(player->pos_y - player->plane_y * (move_speed + 0.1 ));
	x = (int)player->pos_x;
	if (map[x][y] == 0)
		player->pos_y -= player->plane_y * (move_speed );
}

void	move_right(t_player_set *player)
{
	int	y;
	int	x;

	x = (int)(player->pos_x + player->plane_x * (move_speed + 0.1));
	y = (int)player->pos_y;
	if (map[x][y] == 0)
		player->pos_x += player->plane_x * (move_speed  );
	y = (int)(player->pos_y + player->plane_y * (move_speed + 0.1 ));
	x = (int)player->pos_x;
	if (map[x][y] == 0)
		player->pos_y += player->plane_y * (move_speed );
}

void	move_down(t_player_set *player)
{
	int	y;
	int	x;

	x = (int)(player->pos_x - player->dir_x * (move_speed + 0.1));
	y = (int)player->pos_y;
	if (map[x][y] == 0)
		player->pos_x -= player->dir_x * (move_speed  );
	y = (int)(player->pos_y - player->dir_y * (move_speed + 0.1));
	x = (int)player->pos_x;
	if (map[x][y] == 0)
		player->pos_y -= player->dir_y * (move_speed );
}

void	move_up(t_player_set *player)
{
	int	y;
	int	x;

	x = (int)(player->pos_x + player->dir_x * (move_speed + 0.1));
	y = (int)player->pos_y;
	if (map[x][y] == 0)
		player->pos_x += player->dir_x * (move_speed  );
	y = (int)(player->pos_y + player->dir_y * (move_speed + 0.1));
	x = (int)player->pos_x;
	if (map[x][y] == 0)
		player->pos_y += player->dir_y * (move_speed );
}