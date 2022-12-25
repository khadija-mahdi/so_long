NAME = so_long

SRC=  ./utils/get_next_line.c ./utils/get_next_line_utils.c\
 ./utils/ft_printf.c ./utils/ft_printf_utils.c draw.c map_check.c main.c so_long.c utlis.c

OBJ= $(SRC:.c=.o)

CC = cc

CFLAGS=  -Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

$(RM) = rm -f 
  
all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all