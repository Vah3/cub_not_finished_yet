/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:09:21 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/17 17:16:08 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALG_HEADER_H
# define ALG_HEADER_H

# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1024
# define HEIGHT 1024
# define ROT_SPEED 0.1
# define MOVE_SPEED 0.3

typedef struct keys_numbers
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
}	t_key;

typedef struct img_list
{
	void	*image;
	char	*path_to_image;
	char	*addr;
	int		bpp;
	int		size_line;
	int		img_height;
	int		img_len;
	int		endian;
	double	step;
	double	y;
}	t_img;

typedef struct ray_computation
{
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	camerax;
	double	ray_dir_x;
	double	ray_dir_y;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
}	t_calc;

typedef struct draw_components
{
	int	lineheight;
	int	drawstart;
	int	drawend;
}	t_draw;

typedef struct data_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct images
{
	t_img	img1;
	t_img	img2;
	t_img	img3;
	t_img	img4;
}	t_imgs;

typedef struct player_settings
{
	char	face_to;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	pos_x;
	double	pos_y;
	int		for_while;
	t_calc	calc;
	t_draw	draw;
	t_mlx	d_mlx;
	t_key	key;
	t_img	gen_img;
	t_imgs	img;
}	t_player_set;

void	ft_ray_cast(t_player_set *player);
void	pos_dir_camera(t_player_set *player, int x);
void	token_distance_and_side(t_player_set *player);
void	dda_find_wall(t_player_set *player);
void	distance(t_player_set *player);
///
void	drawing_wall(t_player_set *player, int x);
///
void	find_side(t_player_set *player, char *color);
/// 
void	move_up(t_player_set *player);
void	move_down(t_player_set *player);
void	move_right(t_player_set *player);
void	move_left(t_player_set *player);
void	rotate(t_player_set *player, double rot_);
///
int		set_true(int key, void	*param);
///
int		init_images(t_player_set *player);
int		init_mlx(t_player_set *player);
int		inits(t_player_set *player);
void	init_player(t_player_set *player);

#endif
