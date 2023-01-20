/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 11:33:22 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/20 15:00:29 by arommers      ########   odam.nl         */
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
# define WIDTH 256
# define HEIGHT 256

typedef struct s_play {
	int				x_pos;
	int				y_pos;
	int				next_x;
	int				next_y;
	mlx_texture_t	*player_t;
	mlx_image_t		*player_i;
}	t_play;

typedef struct s_img {
	int		width;
	int		height;
	void	*player;
	void	*wall;
	void	*open;
	void	*item;
	void	*exit;
}	t_img;

typedef struct s_map {
	size_t		width;
	size_t		height;
	char		**grid;
}	t_map;

typedef struct s_game {
	int		width;
	int		height;
	int		steps;
	t_map	*map;
	t_img	*img;
	t_play	*play;
	mlx_t	*mlx;
}	t_game;

t_game	*make_array(char *map, t_game *data);
t_map	*init_map(int width, int height);
void	fill_background(t_game *data);
void	free_map(t_map *map);

#endif