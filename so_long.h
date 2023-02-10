/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 11:33:22 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/10 15:00:04 by arommers      ########   odam.nl         */
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

# define PIXELS 64

typedef struct s_img {
	mlx_image_t		*bush;
	mlx_image_t		*grass;
	mlx_image_t		*rupee;
	mlx_image_t		*link;
	mlx_image_t		*link_up;
	mlx_image_t		*link_down;
	mlx_image_t		*link_right;
	mlx_image_t		*link_left;
	mlx_image_t		*exit_closed;
	mlx_image_t		*exit_open;	
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
size_t	count_rupees(t_game *game);
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
t_img	*load_exit_closed(mlx_t *mlx, t_img *texture);
t_img	*load_exit_open(mlx_t *mlx, t_img *texture);
t_img	*initialize_img_struct(mlx_t *mlx);
void	image_select(t_game *data, size_t y, size_t x);
void	load_link(t_game *game, char dir, size_t x, size_t y);

// move functions
void	move_player(t_game *game, char line, char dir);
void	move_select(t_game *game, char line, char dir);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_right(t_game *game);
t_game	*move_left(t_game *game);
void	move_hook(mlx_key_data_t keydata, void *data);

// Map Validation

void	error_message(char *msg);
void	check_map_shape(char **grid);
void	check_empty(char *map);
void	check_empty_lines(char *map);
void	check_map_content(char *map);
void	check_invalid_content(char *map);
void	check_walls(t_game *game);
void	check_horo(t_game *game);
void	check_vert(t_game *game);
void	check_file_extension(char *file);
void	flood_fill(t_game *game);
int		check_path(t_game *temp, size_t x, size_t y);

void	free_grid(char **grid, size_t height);
void	check_game_status(t_game *game);

#endif