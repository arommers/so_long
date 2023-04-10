/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   miscellaneous.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:22:19 by arommers      #+#    #+#                 */
/*   Updated: 2023/03/28 15:54:45 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_message(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	check_game_status(t_game *game)
{
	print_moves(game);
	if (game->collected == game->rupees)
	{
		if (mlx_image_to_window(game->mlx, game->img->exit_open,
				game->exit_x * PIXELS, game->exit_y * PIXELS) < 0)
			error_message("Failed to put image to window");
		game->grid[game->exit_y][game->exit_x] = '0';
		if (game->link_x == game->exit_x && game->link_y == game->exit_y)
		{
			sleep(1);
			mlx_close_window(game->mlx);
			ft_printf("Congratulations!\n");
			ft_printf("You made link rich! 💰💰💰\n");
			ft_printf("He can now sleep in his hole in the ground\n");
			ft_printf("and think about all the stuff he is gonna buy.\n");
		}
	}
}
