/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   directions.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 14:53:00 by arommers      #+#    #+#                 */
/*   Updated: 2023/04/14 09:44:28 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_rupee(t_game *game, int y, int x)
{
	int	rupee_i;

	rupee_i = 0;
	x = x * 64 + 16;
	y = y * 64 + 16;
	while (rupee_i < game->img->rupee->count)
	{
		if (game->img->rupee->instances[rupee_i].x == x
			&& game->img->rupee->instances[rupee_i].y == y)
		{
			game->img->rupee->instances[rupee_i].enabled = false;
		}
		rupee_i++;
	}
}

t_game	*move_up(t_game *game)
{
	if (game->grid[game->link_y - 1][game->link_x] != '1'
		&& game->grid[game->link_y - 1][game->link_x] != 'E')
	{
		if (game->grid[game->link_y - 1][game->link_x] == 'C')
		{
			remove_rupee(game, game->link_y - 1, game->link_x);
			print_rupees(game);
			game->grid[game->link_y - 1][game->link_x] = '0';
			game->collected += 1;
		}
		game->link_y -= 1;
		game->img->link->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->grid[game->link_y + 1][game->link_x] != '1'
		&& game->grid[game->link_y + 1][game->link_x] != 'E')
	{
		if (game->grid[game->link_y + 1][game->link_x] == 'C')
		{
			remove_rupee(game, game->link_y + 1, game->link_x);
			print_rupees(game);
			game->grid[game->link_y + 1][game->link_x] = '0';
			game->collected += 1;
		}
		game->link_y += 1;
		game->img->link->instances[0].y += 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->grid[game->link_y][game->link_x + 1] != '1'
		&& game->grid[game->link_y][game->link_x + 1] != 'E')
	{
		if (game->grid[game->link_y][game->link_x + 1] == 'C')
		{
			remove_rupee(game, game->link_y, game->link_x + 1);
			print_rupees(game);
			game->grid[game->link_y][game->link_x + 1] = '0';
			game->collected += 1;
		}
		game->link_x += 1;
		game->img->link->instances[0].x += 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->grid[game->link_y][game->link_x - 1] != '1'
		&& game->grid[game->link_y][game->link_x - 1] != 'E')
	{
		if (game->grid[game->link_y][game->link_x - 1] == 'C')
		{
			remove_rupee(game, game->link_y, game->link_x - 1);
			print_rupees(game);
			game->grid[game->link_y][game->link_x - 1] = '0';
			game->collected += 1;
		}
		game->link_x -= 1;
		game->img->link->instances[0].x -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}
