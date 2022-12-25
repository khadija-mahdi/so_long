/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:08:36 by kmahdi            #+#    #+#             */
/*   Updated: 2022/12/25 22:29:31 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_path(t_data *data, int x, int y)
{
	if (x <= 0 && y <= 0)
		return ;
	if (data->all_lines[y][x] == '_' || data->all_lines[y][x] == '*')
		return ;
	if (data->all_lines[y][x] == 'E')
	{
		data->reached_e = 1;
		return ;
	}
	if (data->all_lines[y][x] == 'C')
	{
		data->all_lines[y][x] = '_';
		data->c++;
	}
	else
		data->all_lines[y][x] = '*';
	if (data->all_lines[y][x - 1] != '1')
		check_valid_path(data, x - 1, y);
	if (data->all_lines[y][x + 1] != '1')
		check_valid_path(data, x + 1, y);
	if (data->all_lines[y - 1][x] != '1')
		check_valid_path(data, x, y - 1);
	if (data->all_lines[y + 1][x] != '1')
		check_valid_path(data, x, y + 1);
}

void	recover_org_map(t_data *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (data->all_lines[y] != NULL)
	{
		x = 0;
		while (data->all_lines[y][x] != 0)
		{
			if (data->all_lines[y][x] == '_')
				data->all_lines[y][x] = 'C';
			else if (data->all_lines[y][x] == '*')
				data->all_lines[y][x] = '0';
			x++;
		}
		y++;
	}
	data->all_lines[data->y][data->x] = 'P';
}

void	read_map(t_data *data, char *s)
{
	int	fd;
	int	index;

	index = 0;
	fd = open(s, O_RDONLY);
	while (1)
	{
		data->all_lines[index] = remove_nl(get_next_line(fd));
		if (data->all_lines[index] == NULL)
			break ;
		index++;
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		ft_printf("ERROR : \n wrong args \n");
		exit(1);
	}
	data = malloc(sizeof(t_data));
	data->move_count = 0;
	data->coll_count = 0;
	data->coll_collected = 0;
	data->player_direction = 1;
	data->mlx = mlx_init();
	init_window(data, av[1]);
	data->mlx_win = mlx_n ew_window(data->mlx,
			data->width * BLOCK_SIZE, data->height * BLOCK_SIZE, "The_game!");
	check_extension(av[1]);
	read_map(data, av[1]);
	draw(data);
	check_map(data);
	recover_org_map(data);
	mlx_hook(data->mlx_win, 2, 0, ft_key_code, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit_program, data);
	mlx_loop_hook(data->mlx, animatore, data);
	mlx_loop(data->mlx);
}
