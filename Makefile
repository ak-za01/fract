NAME = fractol
NAME_BONUS = fractol_bonus

SRC = mandatory/main.c mandatory/utils.c mandatory/init.c mandatory/mandelbrot.c \
		mandatory/events.c mandatory/julia.c mandatory/helper.c

#SRCB = src/bonus/main_bonus.c src/bonus/burning_bonus.c src/bonus/utils_bonus.c src/bonus/events_bonus.c
OBJ = $(SRC:.c=.o)
#OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I includes -I minilibx-linux
# MLX = -L minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c mandatory/fractol.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all