/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   directions.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 14:53:00 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/03 14:06:38 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	*move_up(t_game *game)
{
	if (game->grid[game->link_y - 1][game->link_x] != '1'
		&& game->grid[game->link_y - 1][game->link_x] != 'E')
	{
		if (game->grid[game->link_y - 1][game->link_x] == 'C')
		{
			game->grid[game->link_y - 1][game->link_x] = '0';
			game->collected += 1;
		}
		game->link_y -= 1;
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
			game->grid[game->link_y + 1][game->link_x] = '0';
			game->collected += 1;
		}
		game->link_y += 1;
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
			game->grid[game->link_y][game->link_x + 1] = '0';
			game->collected += 1;
		}
		game->link_x += 1;
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
			game->grid[game->link_y][game->link_x - 1] = '0';
			game->collected += 1;
		}
		game->link_x -= 1;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}
