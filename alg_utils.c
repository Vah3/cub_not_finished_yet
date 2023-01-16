#include "alg_header.h"

extern int map[24][24];

void	dda_find_wall(t_player_set *player)
{
	player->calc.hit = 0;
	while(player->calc.hit == 0)
	{
		if(player->calc.sideDistX < player->calc.sideDistY)
		{
			player->calc.sideDistX += player->calc.deltaDistX;
			player->calc.mapX += player->calc.stepX;
			player->calc.side = 0;
		}
		else
		{
			player->calc.sideDistY += player->calc.deltaDistY;
			player->calc.mapY += player->calc.stepY;
			player->calc.side = 1;
		}
		if (map[player->calc.mapX][player->calc.mapY] > 0)
			player->calc.hit = 1;
	}
}

void	token_distance_and_side(t_player_set *player)
{
	player->calc.mapX = (int)player->pos_x;
	player->calc.mapY = (int)player->pos_y;
	player->calc.deltaDistX = fabs(1 / player->calc.ray_dir_x);
	player->calc.deltaDistY = fabs(1 / player->calc.ray_dir_y);
	if (player->calc.ray_dir_x < 0)
	{
		player->calc.stepX = -1;
		player->calc.sideDistX = (player->pos_x - player->calc.mapX) * player->calc.deltaDistX;
	}
	else
	{
		player->calc.stepX = 1;
		player->calc.sideDistX = (player->calc.mapX + 1 - player->pos_x) * player->calc.deltaDistX;
	}
	if (player->calc.ray_dir_y < 0)
	{
		player->calc.stepY = -1;
		player->calc.sideDistY = (player->pos_y - player->calc.mapY) * player->calc.deltaDistY;
	}
	else
	{
		player->calc.stepY = 1;
		player->calc.sideDistY = (player->calc.mapY + 1.0 - player->pos_y) * player->calc.deltaDistY;
	}
}

void	pos_dir_camera(t_player_set *player, int x)
{
	player->calc.cameraX = 2 * x / (double)width - 1;
	player->calc.ray_dir_x = player->dir_x + player->plane_x * player->calc.cameraX; 
	player->calc.ray_dir_y = player->dir_y + player->plane_y * player->calc.cameraX;
}

void	ft_ray_cast(t_player_set *player)
{
	int	for_each_pixel;

	for_each_pixel = 0;
	while(for_each_pixel < width)
	{
		pos_dir_camera(player, for_each_pixel);
		token_distance_and_side(player);
		dda_find_wall(player);
		distance(player);
		drawing_wall(player, for_each_pixel);
		for_each_pixel++;
	}
	mlx_put_image_to_window(player->d_mlx.mlx,player->d_mlx.win,player->gen_img.image, 0, 0);
}