/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 11:33:22 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/02 15:47:12 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <memory.h>

#define PIXELS 64

typedef struct s_img {
	mlx_image_t		*bush;
	mlx_image_t		*grass;
	mlx_image_t		*rupee;
	mlx_image_t		*link;
	mlx_image_t		*link_up;
	mlx_image_t		*link_down;
	mlx_image_t		*link_right;
	mlx_image_t		*link_left;
	mlx_image_t		*exit;	
}	t_img;

typedef struct s_game {
	char	**grid;
	size_t	width;
	size_t	height;
	size_t	rupees;
	size_t	steps;
	size_t	collected;
	size_t	link_x;
	size_t	link_y;
	size_t	exit_x;
	size_t	exit_y;
	// char	*map;
	t_img	*img;
	mlx_t	*mlx;
}	t_game;

//make map fucntions

char	*read_map(char *map);
size_t	row_count(char **grid);
t_game	*initialize_game_struct(char **grid);
t_game	*initialize_data(char *map);
void	fill_background(t_game *data);
void	render_map(t_game *data);
size_t	count_items(t_game *game);
size_t	get_link_pos(t_game *game, char c);
size_t	get_exit_pos(t_game *game, char c );

// make images functions
t_img	*load_grass_texture(mlx_t *mlx, t_img *texture);
t_img	*load_bush_texture(mlx_t *mlx, t_img *texture);
t_img	*load_rupee_texture(mlx_t *mlx, t_img *texture);
t_img	*load_link_texture(mlx_t *mlx, t_img *texture);
t_img	*load_link_up(mlx_t *mlx, t_img *texture);
t_img	*load_link_down(mlx_t *mlx, t_img *texture);
t_img	*load_link_right(mlx_t *mlx, t_img *texture);
t_img	*load_link_left(mlx_t *mlx, t_img *texture);
t_img	*load_exit_texture(mlx_t *mlx, t_img *texture);
t_img	*initialize_img_struct(mlx_t *mlx);
void	load_link(t_game *game, char dir, size_t x, size_t y);

// move functions
void	move_player(t_game *game, char line, char dir);
void	move_select(t_game *game, char line, char dir);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_right(t_game *game);
t_game	*move_left(t_game *game);
void	move_hook(mlx_key_data_t keydata, void *data);

#endif