/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 11:49:11 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/03 14:06:38 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	check_game_status(t_game *game)
{
	printf("steps: %zu\n", game->steps);
	if (game->collected == game->rupees)
	{
		mlx_image_to_window(game->mlx, game->img->exit_open,
			game->exit_x * PIXELS, game->exit_y * PIXELS);
		game->grid[game->exit_y][game->exit_x] = '0';
		if (game->link_x == game->exit_x && game->link_y == game->exit_y)
		{
			mlx_close_window(game->mlx);
			printf("YOU DID IT MOTHERFUCKER!!!!\nTHEY SAID IT COULDN'T BE DONE,\nBUT LOOK AT US NOW\n");
		}
	}
}

void	load_link(t_game *game, char dir, size_t x, size_t y)
{
	if (dir == 'u')
		mlx_image_to_window(game->mlx, game->img->link_up, x, y);
	if (dir == 'd')
		mlx_image_to_window(game->mlx, game->img->link_down, x, y);
	if (dir == 'r')
		mlx_image_to_window(game->mlx, game->img->link_right, x, y);
	if (dir == 'l')
		mlx_image_to_window(game->mlx, game->img->link_left, x, y);
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
	mlx_image_to_window (game->mlx, game->img->grass, x, y);
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
