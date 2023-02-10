/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 11:49:11 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/10 16:26:36 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	load_link(t_game *game, char dir, size_t x, size_t y)
{
	if (dir == 'u')
		if (mlx_image_to_window(game->mlx, game->img->link_up, x, y) < 0)
			error_message("Failed to put image to window");
	if (dir == 'd')
		if (mlx_image_to_window(game->mlx, game->img->link_down, x, y) < 0)
			error_message("Failed to put image to window");
	if (dir == 'r')
		if (mlx_image_to_window(game->mlx, game->img->link_right, x, y) < 0)
			error_message("Failed to put image to window");
	if (dir == 'l')
		if (mlx_image_to_window(game->mlx, game->img->link_left, x, y) < 0)
			error_message("Failed to put image to window");
}

void	move_select(t_game *game, char line, char dir)
{
	if (line == 'y')
	{
		if (dir == 'u')
			move_up(game);
		else
			move_down(game);
	}
	if (line == 'x')
	{
		if (dir == 'r')
			move_right(game);
		else
			move_left(game);
	}
}

void	move_player(t_game *game, char line, char dir)
{
	size_t	x;
	size_t	y;

	x = game->link_x * PIXELS;
	y = game->link_y * PIXELS;
	if (mlx_image_to_window (game->mlx, game->img->grass, x, y) < 0)
		error_message("Failed to put image to window");
	move_select(game, line, dir);
	x = game->link_x * PIXELS;
	y = game->link_y * PIXELS;
	load_link(game, dir, x, y);
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'r');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'l');
}
