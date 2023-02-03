/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 11:51:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/03 14:06:38 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	fill_background(t_game *data)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_image_to_window(data->mlx, data->img->grass, x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
	}
}

void	render_map(t_game *data)
{
	size_t		x;
	size_t		y;
	int			img_size;

	x = 0;
	y = 0;
	img_size = 32;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->grid[y][x] == '1')
				mlx_image_to_window(data->mlx, data->img->bush, x * PIXELS, y * PIXELS);
			if (data->grid[y][x] == 'C')
				mlx_image_to_window(data->mlx, data->img->rupee,
					x * PIXELS + img_size / 2, y * PIXELS + img_size / 2);
			if (data->grid[y][x] == 'P')
				mlx_image_to_window(data->mlx, data->img->link, x * PIXELS, y * PIXELS);
			if (data->grid[y][x] == 'E')
				mlx_image_to_window(data->mlx, data->img->exit_closed, x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
	}
}
