/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 11:33:22 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/29 16:58:19 by arommers      ########   odam.nl         */
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
	mlx_image_t		*exit;	
}	t_img;

typedef struct s_game {
	size_t	width;
	size_t	height;
	// size_t	items;
	// size_t	steps;
	// size_t	collected;
	// size_t	player_x;
	// size_t	player_y;
	// size_t	exit_x;
	// size_t	exit_y;
	// char	*map;
	char	**grid;
	t_img	*img;
	mlx_t	*mlx;
}	t_game;

//make map fucntions

char	*read_map(char *map);
size_t	row_count(char **grid);
t_game	*initialize_game_struct(char **grid);
t_game	*initialize_data(char *map);
t_game	*update_game_struct(mlx_t *mlx, t_img *images, t_game *game);
void	fill_background(t_game *data);
void	render_map(t_game *data);

// make images functions
t_img	*load_grass_texture(mlx_t *mlx, t_img *texture);
t_img	*load_bush_texture(mlx_t *mlx, t_img *texture);
t_img	*load_rupee_texture(mlx_t *mlx, t_img *texture);
t_img	*load_link_texture(mlx_t *mlx, t_img *texture);
t_img	*load_exit_texture(mlx_t *mlx, t_img *texture);
t_img	*initialize_img_struct(mlx_t *mlx);

// size_t	column_count(char **grid);

#endif