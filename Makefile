NAME = so_long

SRCS = get_next_line.c  get_next_line_utils.c so_long.c ft_anim_enemies.c ft_animations.c ft_check_map.c ft_draw_images.c ft_draw_map.c ft_endgame.c ft_enemy_move.c ft_exit.c ft_form_check.c ft_keybind.c ft_map.c ft_walls_check.c

LIBFT = ./libs/libft/
PRINTF = ./libs/ft_printf/
MLX = ./libs/mlx
GNL = ./includes/

CC = gcc

FLAGS = -Wextra -Wall -Werror -g

LINKS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM = rm -f

OBJ = $(SRCS:.c=.o)

INCLUDE = -I${LIBFT} -I${PRINTF} -I${MLX} -I${GNL}

LIBS = -L${LIBFT} -lft -L${PRINTF} -printf -L${MLX} -lmlx

%.o:%.c
	${CC} ${FLAGS} ${INCLUDE} -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: ${NAME}

${NAME}:	${OBJ}
	make -C ${LIBFT}
	make -C ${PRINTF}
	${CC} ${FLAGS} ${INCLUDE} ${LIBS} ${PRINTF}libftprintf.a ${LINKS} ${OBJ} -o ${NAME}

# ${OBJ}: ${SRCS}
# 	${CC} ${FLAGS} ${INCLUDE} -c $< -o

clean:
	@rm -rf ${OBJ}
	make clean -C ${LIBFT}
	make clean -C ${PRINTF}

fclean: clean
	@rm -f ${NAME}
	make fclean -C ${LIBFT}
	make fclean -C ${PRINTF}

re: fclean all
