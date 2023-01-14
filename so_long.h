/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 11:33:22 by arommers      #+#    #+#                 */
/*   Updated: 2023/01/14 15:32:43 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# define WIDTH 256
# define HEIGHT 256

typedef struct s_img
{
	
}		t_img

typedef struct s_game
{
	char	**grid;
	int		width;
	int		heigh;
	int		steps;
	t_img	img;
	t_map	map;
	void	*mlx;	
}		t_game

int32_t	main(void);

#endif