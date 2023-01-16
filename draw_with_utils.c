#include "alg_header.h"

char	*which_image(t_player_set *player, int which,int x)
{
	int y;
	char *c;

	c = NULL;
	if (which == 1)
	{
		y = (int)floor(player->img.img1.y);
		c = player->img.img1.addr + (y * player->img.img1.size_line + x * (player->img.img1.bpp / 8));
		player->img.img1.y += player->img.img1.step;
	}
	else if (which == 2)
	{
		y = (int)floor(player->img.img2.y);
		c = player->img.img2.addr + (y * player->img.img2.size_line + x * (player->img.img2.bpp / 8));
		player->img.img2.y += player->img.img2.step;
	}
	else if (which == 3)
	{
		y = (int)floor(player->img.img3.y);
		c = player->img.img3.addr + (y * player->img.img3.size_line + x * (player->img.img3.bpp / 8));
		player->img.img3.y += player->img.img3.step;
	}
	else if (which == 4)
	{
		y = (int)floor(player->img.img4.y);
		c = player->img.img4.addr + (y * player->img.img4.size_line + x * (player->img.img4.bpp / 8));
		player->img.img4.y += player->img.img4.step;
	}
	return (c);
}

void	set_color(t_player_set *player, char *color, int which)
{
	double wallx;
	int	x;
	int	y;
	char *c;

	c = NULL;
	if (player->calc.side == 1)
		wallx = player->pos_x + player->calc.perpWallDist * player->calc.ray_dir_x;
	else if (player->calc.side == 0)
		wallx = player->pos_y + player->calc.perpWallDist * player->calc.ray_dir_y;
	wallx -= floor(wallx);
	wallx = player->img.img1.img_height * wallx;
	wallx = floor(wallx);
	x = (int)wallx;
	c = which_image(player, which,x);
	*(int*)color = *(int*)c;
}

void	find_side(t_player_set *player,char *color)
{
	double wallx;
	char *c;
	int	x;
	int	y_;
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

void	find_step_for_image(t_player_set * player)
{
	player->img.img1.step = (double)player->img.img1.img_height / (double)player->draw.lineHeight;
	player->img.img1.y = 0;
	if (player->calc.perpWallDist < 1)
		player->img.img1.y = ((double)player->img.img1.img_height - (double)player->img.img1.img_height * player->calc.perpWallDist) / 2;
	player->img.img2.step = (double)player->img.img2.img_height / (double)player->draw.lineHeight;
	if (player->calc.perpWallDist < 1)
		player->img.img2.y = ((double)player->img.img1.img_height - (double)player->img.img1.img_height * player->calc.perpWallDist) / 2;
	player->img.img2.y = 0;
	player->img.img3.step = (double)player->img.img3.img_height / (double)player->draw.lineHeight;
	if (player->calc.perpWallDist < 1)
		player->img.img3.y = ((double)player->img.img1.img_height - (double)player->img.img1.img_height * player->calc.perpWallDist) / 2;
	player->img.img3.y = 0;
	player->img.img4.step = (double)player->img.img4.img_height / (double)player->draw.lineHeight;
	if (player->calc.perpWallDist < 1)
		player->img.img4.y = ((double)player->img.img1.img_height - (double)player->img.img1.img_height * player->calc.perpWallDist) / 2;
	player->img.img4.y = 0;
}

void	drawing_wall(t_player_set *player, int x)
{
	int	y;
	int	ceil = 0;
	int	floor = height - 1;
	char *addr;
	int	color;
	y = player->draw.drawStart;
	find_step_for_image(player);
	while(ceil < y - 1)
	{
		addr = player->gen_img.addr + (ceil * player->gen_img.size_line + x * player->gen_img.bpp / 8);
		*(int*)addr = 0xff8080;
		ceil++;
	}
	while(floor >= player->draw.drawEnd)
	{
		addr = player->gen_img.addr + (floor * player->gen_img.size_line + x * player->gen_img.bpp / 8);
		*(int*)addr = 0x660000;
		floor--;
	}
	while(y < player->draw.drawEnd)
	{
		addr = player->gen_img.addr + (y * player->gen_img.size_line + x * player->gen_img.bpp / 8);
		find_side(player,addr);
		y++;
	}
}