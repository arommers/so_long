/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:55:42 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/20 11:57:51 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_status(const t_game *game)
{
	int	count;

	count = 0;
	while (count < game->img->enemy->count)
	{
		if (game->link_x * PIXELS
			== (size_t)game->img->enemy->instances[count].x
			&& game->link_y * PIXELS
			== (size_t)game->img->enemy->instances[count].y)
		{
			mlx_close_window(game->mlx);
			ft_printf ("Ow no! Link got killed by a ghost 😱\n");
			ft_printf ("Try again!\n");
		}
		count++;
	}
}

static void	move_all(const t_game *game, int count)
{
	t_var			var;

	var.x = &game->img->enemy->instances[count].x;
	var.y = &game->img->enemy->instances[count].y;
	var.ran_x = (rand() % 3 - 1) * 64;
	var.ran_y = (rand() % 3 - 1) * 64;
	var.index_x = *var.x + var.ran_x;
	var.index_y = *var.y + var.ran_y;
	if (var.index_x != 0)
		var.index_x /= PIXELS;
	if (var.index_y != 0)
		var.index_y /= PIXELS;
	if (game->grid[var.index_y][var.index_x] != '1'
		&& game->grid[var.index_y][var.index_x] != 'E')
	{
			*var.x += var.ran_x;
			*var.y += var.ran_y;
	}
}

void	enemy_patrol(void *temp)
{
	const t_game	*game = temp;
	int				count;
	static int		i;

	count = 0;
	check_status(game);
	if (i++ < EMOVE)
		return ;
	while (count < game->img->enemy->count)
	{
		move_all (game, count);
		count++;
	}
	i = 0;
}

t_img	*load_enemy_texture(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("./Sprites/Enemy.png");
	if (!enemy)
		error_message("Problem with loading png");
	texture->enemy = mlx_texture_to_image(mlx, enemy);
	if (!texture->enemy)
		error_message("Problem with texture to image");
	mlx_delete_texture(enemy);
	return (texture);
}
