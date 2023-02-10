/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_link.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 14:26:57 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/10 14:24:19 by arommers      ########   odam.nl         */
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

t_img	*load_link_up(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link_up;

	link_up = mlx_load_png("./Sprites/Link_Up.png");
	if (!link_up)
		error_message("Problem with loading png");
	texture->link_up = mlx_texture_to_image(mlx, link_up);
	if (!texture->link_up)
		error_message("Problem with texture to image");
	mlx_delete_texture(link_up);
	return (texture);
}

t_img	*load_link_down(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link_down;

	link_down = mlx_load_png("./Sprites/Link_Down.png");
	if (!link_down)
		error_message("Problem with loading png");
	texture->link_down = mlx_texture_to_image(mlx, link_down);
	if (!texture->link_down)
		error_message("Problem with texture to image");
	mlx_delete_texture(link_down);
	return (texture);
}

t_img	*load_link_right(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link_right;

	link_right = mlx_load_png("./Sprites/Link_Right.png");
	if (!link_right)
		error_message("Problem with loading png");
	texture->link_right = mlx_texture_to_image(mlx, link_right);
	if (!texture->link_right)
		error_message("Problem with texture to image");
	mlx_delete_texture(link_right);
	return (texture);
}

t_img	*load_link_left(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link_left;

	link_left = mlx_load_png("./Sprites/Link_Left.png");
	if (!link_left)
		error_message("Problem with loading png");
	texture->link_left = mlx_texture_to_image(mlx, link_left);
	if (!texture->link_left)
		error_message("Problem with texture to image");
	mlx_delete_texture(link_left);
	return (texture);
}
