NAME = fractol
NAME_BONUS = fractol_bonus

SRC = mandatory/main.c mandatory/utils.c
#SRCB = src/bonus/main_bonus.c src/bonus/burning_bonus.c src/bonus/utils_bonus.c src/bonus/events_bonus.c
OBJ = $(SRC:.c=.o)
#OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all