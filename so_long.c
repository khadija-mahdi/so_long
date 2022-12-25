/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:51:00 by kmahdi            #+#    #+#             */
/*   Updated: 2022/12/25 22:18:02 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_data *data, char *s)
{
	char	*line;
	int		fd;

	data->height = 0;
	data->width = 0;
	fd = open(s, O_RDONLY);
	while (1)
	{
		line = remove_nl(get_next_line(fd));
		if (data->height == 0 && line == NULL)
		{
			ft_printf("ERROR : \n map error!! \n");
			exit(1);
		}
		if (line == NULL)
			break ;
		data->width = ft_strlen(line);
		data->height++;
		free(line);
	}
	data->all_lines = malloc((data->height + 1) * sizeof(char *));
	close(fd);
	init_blocks(data);
}

int	check_walls_positions(t_data *data, int x, int y)
{
	if (data->all_lines[y][x] == '1')
		return (0);
	if (data->all_lines[y][x] == 'C')
	{
		data->coll_collected++;
		data->all_lines[y][x] = '0';
	}
	if (data->all_lines[y][x] == 'E' )
	{
		if (data->coll_count == data->coll_collected)
		{
			ft_printf("CONGRATULATIONS ,THE PROGRAM END SUCCESSFULLY !!");
			exit (1);
		}
		else
			return (0);
	}
	data->move_count++;
	ft_printf("MOVES : %d\n", data->move_count);
	return (1);
}

int	ft_key_code_one(int key_code, t_data *data)
{
	if (key_code == ESC)
	{
		ft_printf("Exit the program with the 'ESC'  button !");
		exit(1);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->m_blocks->nan,
		data->x * BLOCK_SIZE, data->y * BLOCK_SIZE);
	if (key_code == LEFT && check_walls_positions(data, data->x - 1, data->y))
	{
		data->x -= 1;
		data->player_direction = -1;
	}
	if (key_code == RIGHT && check_walls_positions(data, data->x + 1, data->y))
	{	
		data->x += 1;
		data->player_direction = 1;
	}
	return (0);
}

int	ft_key_code_tow(int key_code, t_data *data)
{
	if (key_code == DOWN && check_walls_positions(data, data->x, data->y + 1))
		data->y += 1;
	if (key_code == UP && check_walls_positions(data,
			data->x, data->y - 1))
		data->y -= 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->m_blocks->nan,
		data->x * BLOCK_SIZE, data->y * BLOCK_SIZE);
	if (data->player_direction == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->m_blocks->player,
			data->x * BLOCK_SIZE, data->y * BLOCK_SIZE);
	else
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->m_blocks->left_player,
			data->x * BLOCK_SIZE, data->y * BLOCK_SIZE);
	return (0);
}

int	ft_key_code(int key_code, t_data *data)
{
	ft_key_code_one(key_code, data);
	ft_key_code_tow(key_code, data);
	return (0);
}
