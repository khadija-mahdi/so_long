/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:37:43 by kmahdi            #+#    #+#             */
/*   Updated: 2022/12/25 22:28:32 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_formate(t_data *data)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (data->all_lines[index] != NULL)
	{
		j = 0;
		while (data->all_lines[index][j])
		{
			if (data->all_lines[index][j] != '1'
					&& data->all_lines[index][j] != '0'
					&& data->all_lines[index][j] != 'E'
					&& data->all_lines[index][j] != 'P'
					&& data->all_lines[index][j] != 'C'
					&& data->all_lines[index][j] != '\n')
			{
				ft_printf("ERROR :\n wrong character !!\n");
				exit (1);
			}
			j++;
		}
		index++;
	}
}

void	check_rect_map(t_data *data)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (data->all_lines[index] != NULL)
	{
		if (ft_strlen(data->all_lines[index]) != data->width)
		{
			ft_printf("ERROR : \n THE MAP ISN'T RECTANGULAR !\n");
			exit (1);
		}
		index++;
	}
}

void	check_blocks(t_data *data)
{
	int	index;

	index = 0;
	if (elem_numb(data, 'P') != 1 || elem_numb(data, 'C') < 1 \
		|| elem_numb(data, 'E') != 1)
	{
		ft_printf("ERROR : \n wrong element !! \n");
		exit(1);
	}
}

void	check_walls(t_data *data)
{
	int	index;
	int	j;

	index = 0;
	while (index < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (j == 0 || index == 0 || index == (data->height - 1)
				|| j == (data->width - 1))
			{
				if (data->all_lines[index][j] != '1')
				{
					ft_printf("ERROR : \n ERROR WALLS!! \n");
					exit (1);
				}
			}
			j++;
		}
		index++;
	}
}

void	check_map(t_data *data)
{
	data->c = 0;
	data->reached_e = 0;
	check_rect_map(data);
	check_walls(data);
	check_map_formate(data);
	check_blocks(data);
	check_valid_path(data, data->x, data->y);
	if (data->c != data->coll_count || data->reached_e != 1)
	{
		ft_printf("ERROR : \n path is not valide ! \n");
		exit(1);
	}
}
