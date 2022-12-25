/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 07:41:37 by kmahdi            #+#    #+#             */
/*   Updated: 2022/12/25 22:19:04 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_blocks(t_data *data)
{
	t_block		*blocks;

	blocks = malloc(sizeof(t_block));
	blocks->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",
			&data->image_w, &data->image_h);
	blocks->food = mlx_xpm_file_to_image(data->mlx, "./textures/food.xpm",
			&data->image_w, &data->image_h);
	blocks->player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm",
			&data->image_w, &data->image_h);
	blocks->map_exit = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm",
			&data->image_w, &data->image_h);
	blocks->nan = mlx_xpm_file_to_image(data->mlx, "./textures/nan.xpm",
			&data->image_w, &data->image_h);
	blocks->left_player = mlx_xpm_file_to_image(data->mlx,
			"./textures/left_player.xpm", &data->image_w, &data->image_h);
	blocks->open_door = mlx_xpm_file_to_image(data->mlx,
			"./textures/open_door.xpm", &data->image_w, &data->image_h);
	if (!(blocks->wall) || !(blocks->food) || !(blocks->player)
		||!(blocks->map_exit) || !(blocks->nan))
	{
		ft_printf("ERROR : \n There is no object !!\n");
		exit (1);
	}
	data->m_blocks = blocks;
}

void	draw_object_with_backgourd(t_data *data, void *object, int j, int index)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->m_blocks->nan, j * BLOCK_SIZE, index * BLOCK_SIZE);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		object, j * BLOCK_SIZE, index * BLOCK_SIZE);
}

void	draw_pg_ex(int index, t_data *data)
{
	int	j;

	j = 0;
	while (data->all_lines[index][j] != 0)
	{
		if (data->all_lines[index][j] == 'E')
		{
			data->door_x = j;
			data->door_y = index;
			animatore(data);
		}
		if (data->all_lines[index][j] == '0')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->m_blocks->nan, j * BLOCK_SIZE, index * BLOCK_SIZE);
		j++;
	}
}

void	draw_w_c_p(int index, t_data *data)
{
	int	j;

	j = 0;
	while (data->all_lines[index][j] != 0)
	{
		if (data->all_lines[index][j] == '1')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->m_blocks->wall, j * BLOCK_SIZE, index * BLOCK_SIZE);
		if (data->all_lines[index][j] == 'C')
		{
			draw_object_with_backgourd(data, data->m_blocks->food, j, index);
			data->coll_count++;
		}
		if (data->all_lines[index][j] == 'P')
		{
			data->x = j;
			data->y = index;
			draw_object_with_backgourd(data, data->m_blocks->player, j, index);
		}
		j++;
	}
}

void	draw(t_data *data)
{
	int	index;
	int	j;

	index = 0;
	while (data->all_lines[index] != NULL)
	{
		j = 0;
		draw_pg_ex(index, data);
		draw_w_c_p(index, data);
		index++;
	}
}
