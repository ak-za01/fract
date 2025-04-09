NAME = fractol

SRC = mandatory/fract.c mandatory/utils.c mandatory/init.c mandatory/render.c \
		mandatory/events.c mandatory/helper.c

SRCB = bonus/fract_bonus.c bonus/utils_bonus.c bonus/render_bonus.c \
		bonus/mandelbox_bonus.c bonus/events_bonus.c bonus/init_bonus.c \
		bonus/helper_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I includes -I minilibx-linux
# MLX = -L minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

bonus: $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) $(MLX) -o $(NAME)

mandatory/%.o: mandatory/%.c mandatory/fract_ol.h
	@$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/fract_ol_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: clean