/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 11:49:11 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/02 15:54:19 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

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

t_game	*move_up(t_game *game)
{
	if (game->grid[game->link_y - 1][game->link_x] != '1')
	{
		if (game->grid[game->link_y - 1][game->link_x] == 'C')
		{
			game->grid[game->link_y - 1][game->link_x] = '0';
			game->collected += 1;
		}
		game->link_y -= 1;
		game->steps += 1;
	}
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->grid[game->link_y + 1][game->link_x] != '1')
	{
		if (game->grid[game->link_y + 1][game->link_x] == 'C')
		{
			game->grid[game->link_y + 1][game->link_x] = '0';
			game->collected += 1;
		}
		game->link_y += 1;
		game->steps += 1;
	}
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->grid[game->link_y][game->link_x + 1] != '1')
	{
		if (game->grid[game->link_y][game->link_x + 1] == 'C')
		{
			game->grid[game->link_y][game->link_x + 1] = '0';
			game->collected += 1;
		}
		game->link_x += 1;
		game->steps += 1;
	}
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->grid[game->link_y][game->link_x - 1] != '1')
	{
		if (game->grid[game->link_y][game->link_x - 1] == 'C')
		{
			game->grid[game->link_y][game->link_x - 1] = '0';
			game->collected += 1;
		}
		game->link_x -= 1;
		game->steps += 1;
	}
	return (game);
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
	// if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	// 	close_window(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'r');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'l');
}
