/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Link.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 14:26:57 by arommers      #+#    #+#                 */
/*   Updated: 2023/02/02 14:32:48 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	*load_link_texture(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link;

	link = mlx_load_png("./Sprites/Link.png");
	if (!link)
		return (NULL);
	texture->link = mlx_texture_to_image(mlx, link);
	if (!texture->link)
		return (NULL);
	mlx_delete_texture(link);
	return (texture);
}

t_img	*load_link_up(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link_up;

	link_up = mlx_load_png("./Sprites/Link_Up.png");
	if (!link_up)
		return (NULL);
	texture->link_up = mlx_texture_to_image(mlx, link_up);
	if (!texture->link_up)
		return (NULL);
	mlx_delete_texture(link_up);
	return (texture);
}

t_img	*load_link_down(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link_down;

	link_down = mlx_load_png("./Sprites/Link_Down.png");
	if (!link_down)
		return (NULL);
	texture->link_down = mlx_texture_to_image(mlx, link_down);
	if (!texture->link_down)
		return (NULL);
	mlx_delete_texture(link_down);
	return (texture);
}

t_img	*load_link_right(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link_right;

	link_right = mlx_load_png("./Sprites/Link_Right.png");
	if (!link_right)
		return (NULL);
	texture->link_right = mlx_texture_to_image(mlx, link_right);
	if (!texture->link_right)
		return (NULL);
	mlx_delete_texture(link_right);
	return (texture);
}

t_img	*load_link_left(mlx_t *mlx, t_img *texture)
{
	mlx_texture_t	*link_left;

	link_left = mlx_load_png("./Sprites/Link_Left.png");
	if (!link_left)
		return (NULL);
	texture->link_left = mlx_texture_to_image(mlx, link_left);
	if (!texture->link_left)
		return (NULL);
	mlx_delete_texture(link_left);
	return (texture);
}
