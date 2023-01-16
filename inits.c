#include "alg_header.h"

int	init_images(t_player_set *player)
{
	player->img.img1.path_to_image = "wall1.xpm";
	player->img.img1.image = mlx_xpm_file_to_image(player->d_mlx.mlx, player->img.img1.path_to_image, &player->img.img1.img_height,&player->img.img1.img_len);
	if(player->img.img1.image == NULL)
		return (1);
	player->img.img1.addr = mlx_get_data_addr(player->img.img1.image,&player->img.img1.bpp,&player->img.img1.size_line,&player->img.img1.endian);
	player->img.img2.path_to_image = "wall2.xpm";
	player->img.img2.image = mlx_xpm_file_to_image(player->d_mlx.mlx, player->img.img2.path_to_image, &player->img.img2.img_height,&player->img.img2.img_len);
	if(player->img.img2.image == NULL)
		return (1);
	player->img.img2.addr = mlx_get_data_addr(player->img.img2.image,&player->img.img2.bpp,&player->img.img2.size_line,&player->img.img2.endian);
	player->img.img3.path_to_image = "wall3.xpm";
	player->img.img3.image = mlx_xpm_file_to_image(player->d_mlx.mlx, player->img.img3.path_to_image, &player->img.img3.img_height,&player->img.img3.img_len);
	if(player->img.img3.image == NULL)
		return (1);
	player->img.img3.addr = mlx_get_data_addr(player->img.img3.image,&player->img.img3.bpp,&player->img.img3.size_line,&player->img.img3.endian);
	player->img.img4.path_to_image = "wall4.xpm";
	player->img.img4.image = mlx_xpm_file_to_image(player->d_mlx.mlx, player->img.img4.path_to_image, &player->img.img4.img_height,&player->img.img4.img_len);
	if(player->img.img4.image == NULL)
		return (1);
	player->img.img4.addr = mlx_get_data_addr(player->img.img4.image,&player->img.img4.bpp,&player->img.img4.size_line,&player->img.img4.endian);
	return (0);
}

int	init_mlx(t_player_set *player)
{
	player->d_mlx.mlx = mlx_init();
	if (player->d_mlx.mlx == NULL)
		return (1);
	player->d_mlx.win = mlx_new_window(player->d_mlx.mlx, width, height, "cub");
	if (player->d_mlx.win == NULL)
		return (1);
	player->gen_img.image = mlx_new_image(player->d_mlx.mlx,width,height);
	if (player->gen_img.image == NULL)
		return (1);
	player->gen_img.addr = mlx_get_data_addr(player->gen_img.image,&player->gen_img.bpp,&player->gen_img.size_line,&player->gen_img.endian);
	if (player->gen_img.addr == NULL)
		return (1);
	return (0);
}

int	inits(t_player_set *player)
{
	if (init_mlx(player))
	{
		write(2, "mlx_error\n", 10);
		return (1);
	}
	init_player(player);
	if (init_images(player))
	{
		write(2, "There is invalid file\n", 22 );
		return (1);
	}
	return (0);
}