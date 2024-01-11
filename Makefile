NAME = so_long

SRCS = get_next_line.c  get_next_line_utils.c so_long.c ft_check_map.c ft_draw_images.c ft_draw_map.c ft_endgame.c ft_exit.c ft_form_check.c ft_keybind.c ft_map.c ft_walls_check.c

LIBFT_DIR = libs/libft
LIBFT = libs/libft/libft.a

PRINTF_DIR = libs/ft_printf
PRINTF = libs/ft_printf/libftprintf.a

MLX = mlx_linux/
GNL = includes/

CC = gcc

FLAGS = -Wextra -Wall -Werror -g

#LINKS = -L${LIBFT_DIR} -lft -L${PRINTF_DIR} -l:libftprintf.a -L${MLX} -lmlx -lXext -lX11

LINKS = -L${LIBFT_DIR} -lft -L${PRINTF_DIR} -lftprintf 

RM = rm -f

OBJ = $(SRCS:.c=.o)

INCLUDE = -I${LIBFT_DIR} -I${PRINTF_DIR} -I${MLX} -I${GNL}

%.o:%.c
	${CC} ${FLAGS} ${INCLUDE} -I/usr/include -Imlx_linux -O3 -c $< -o $@ -lXext -lX11 -lmlx_Linux

all: ${LIBFT} ${PRINTF} ${NAME}

${NAME}: ${OBJ}
	@make -C ${MLX}
	#@${CC} ${FLAGS} ${LINKS} ${LIBFT} ${PRINTF} ${OBJ} ${LINKS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}
	@${CC} ${FLAGS} ${LIBFT} ${PRINTF} ${OBJ} -o ${NAME} ${LINKS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
${LIBFT}:
	@make -C ${LIBFT_DIR}

${PRINTF}:
	@make -C ${PRINTF_DIR}

clean:
	@${RM} ${OBJ}
	@make clean -C ${LIBFT_DIR}
	@make clean -C ${PRINTF_DIR}

fclean: clean
	@${RM} ${NAME} ${OBJ}
	@make fclean -C ${LIBFT_DIR}
	@make fclean -C ${PRINTF_DIR}
	@make clean -C ${MLX}

re: fclean all

.PHONY: all clean fclean re
