/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 11:49:11 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/18 11:37:04 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	load_link(t_game *game, char dir)
{
	if (dir == 'u')
		mlx_draw_texture(game->img->link, game->link_up, 0, 0);
	if (dir == 'd')
		mlx_draw_texture(game->img->link, game->link_down, 0, 0);
	if (dir == 'r')
		mlx_draw_texture(game->img->link, game->link_right, 0, 0);
	if (dir == 'l')
		mlx_draw_texture(game->img->link, game->link_left, 0, 0);
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
	uint32_t	x;
	uint32_t	y;

	// x = game->link_x * PIXELS;
	// y = game->link_y * PIXELS;
	// // if (mlx_image_to_window (game->mlx, game->img->grass, x, y) < 0)
	// // 	error_message("Failed to put image to window");
	move_select(game, line, dir);
	x = game->img->link->instances[0].x;
	y = game->img->link->instances[0].y;
	load_link(game, dir);
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
