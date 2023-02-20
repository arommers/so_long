/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_link.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 14:26:57 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/20 10:42:53 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	*load_link_texture(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link;

	link = mlx_load_png("./Sprites/Link.png");
	if (!link)
		error_message("Problem with loading png");
	texture->link = mlx_texture_to_image(mlx, link);
	if (!texture->link)
		error_message("Problem with texture to image");
	mlx_delete_texture(link);
	return (texture);
}
