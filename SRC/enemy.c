/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:55:42 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/18 12:26:29 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

typedef struct s_var {
	int				ran_x;
	int				ran_y;
	int				*x;
	int				*y;
	int				index_x;
	int				index_y;
}	t_var;

void	check_status(const t_game *game)
{
	if (game->link_x * PIXELS == (size_t)game->img->enemy->instances->x
		&& game->link_y * PIXELS == (size_t)game->img->enemy->instances-> y)
	{
		mlx_close_window(game->mlx);
	}
}

void	enemy_patrol(void *temp)
{
	const t_game	*game = temp;
	t_var			var;
	static int		i;

	i++;
	check_status(game);
	if (i < EMOVE)
		return ;
	var.x = &game->img->enemy->instances->x;
	var.y = &game->img->enemy->instances->y;
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
