/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:27:01 by kmahdi            #+#    #+#             */
/*   Updated: 2022/12/25 22:43:23 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

# define BLOCK_SIZE 48
# define RIGHT 124
# define LEFT 123
# define DOWN 125
# define UP 126
# define ESC 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 434
# endif

typedef struct s_block {
	void	*wall;
	void	*food;
	void	*player;
	void	*background;
	void	*nan;
	void	*map_exit;
	void	*left_player;
	void	*open_door;
}				t_block;

typedef struct s_data{
	void			*mlx;
	void			*mlx_win;
	char			**all_lines;
	int				width;
	int				height;
	int				y;
	int				x;
	int				c;
	int				image_w;
	int				image_h;
	int				move_count;
	int				coll_count;
	int				coll_collected;
	int				door_x;
	int				door_y;
	int				reached_e;
	int				player_direction;
	struct s_block	*m_blocks;	
}				t_data;

char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsg(unsigned int n);
void	init_blocks(t_data *data);
void	init_window(t_data *data, char *s);
void	draw(t_data *data);
int		check_walls_positions(t_data *data, int x, int y);
int		ft_key_code(int key_code, t_data *data);
void	check_rect_map(t_data *data);
void	check_map_formate(t_data *data);
void	check_extension(char *av);
void	check_map(t_data *data);
char	*remove_nl(char *s);
int		elem_numb(t_data *data, char c);
void	check_walls(t_data *data);
void	draw_object_with_backgourd(t_data *data,
			void *object, int j, int index);
int		animatore(t_data *data);
int		ft_exit_program(void);
int		ft_key_code_i(int key_code, t_data *data);
void	check_valid_path(t_data *data, int x, int y);
#endif
