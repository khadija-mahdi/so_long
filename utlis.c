/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 06:44:03 by kmahdi            #+#    #+#             */
/*   Updated: 2022/12/25 22:16:55 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*remove_nl(char *s)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			s[i] = 0;
		i++;
	}
	return (s);
}

int	ft_exit_program(void)
{
	ft_printf("Exit the program with the X !!");
	exit (1);
}

int	elem_numb(t_data *data, char c)
{
	int	index;
	int	j;
	int	elem_count;

	index = 0;
	elem_count = 0;
	while (data->all_lines[index] != NULL)
	{
		j = 0;
		while (data->all_lines[index][j] != 0)
		{
			if (data->all_lines[index][j] == c)
				elem_count++;
			j++;
		}
		index++;
	}
	return (elem_count);
}

int	animatore(t_data *data)
{
	if (data->coll_count == data->coll_collected)
		draw_object_with_backgourd(data,
			data->m_blocks->open_door, data->door_x,
			data->door_y);
	else
		draw_object_with_backgourd(data, data->m_blocks->map_exit,
			data->door_x, data->door_y);
	return (0);
}

void	check_extension(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	i--;
	if (av[i] != 'r' || av[i - 1] != 'e'
		|| av[i - 2] != 'b' || av[i - 3] != '.')
	{
		ft_printf("ERROR : \n wrong extension !!");
		exit(1);
	}	
}
