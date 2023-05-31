NAME = so_long

SRCS = get_next_line.c  get_next_line_utils.c so_long.c ft_animations.c ft_check_map.c ft_draw_images.c ft_draw_images.c ft_draw_map.c ft_endgame.c ft_enemies.c ft_enemy_move.c ft_exit.c ft_form_check.c ft_keybind.c ft_map.c ft_walls_check.c

LIBFT = ./include/libft/
PRINTF = ./include/ft_printf/

CC = gcc

FLAGS = -Wextra -Wall -Werror -g

LINKS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

OBJ = $(SRCS:.c=.o)

INCLUDE = -I${LIBFT} -I${PRINTF}

LIBS = -L${LIBFT} -lft

%.o:%.c
	${CC} ${FLAGS} ${INCLUDE} -c $< -o $@

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
