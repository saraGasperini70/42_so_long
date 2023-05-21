/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:38:00 by sgasperi          #+#    #+#             */
/*   Updated: 2023/05/17 12:45:40 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "get_next_line.h"
# include "include/libft/libft.h"
# include "include/ft_printf/ft_printf.h"
# include <math.h>
# include <fcntl.h>
# include <time.h>

//struct
typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

typedef struct s_image
{
	void	*wall;
	void	*player1;
	void	*enemy1;
	void	*escape;
	void	*collectible;
	void	*floor;
}	t_image;

typedef struct s_program
{
	void		*ptr;
	void		*window;
	int			player_x;
	int			player_y;
	char		**map;
	t_image		*image;
	int			map_height;
	int			map_width;
	int			moves;
	int			collectibles;
	int			tStamp;
	int			loop;
	int			img_size;
	int			end_result;
}	t_program;

enum s_keys
{
	KEY_UP=13,
	KEY_DOWN=1,
	KEY_LEFT=0,
	KEY_RIGHT=2,
	KEY_ESC=53,
};

enum s_tilesize
{
	SIZE_X=64,
	SIZE_Y=64,
};

int		ft_exit(t_program *program);
void 	ft_moveup(t_program *program);
void 	ft_movedown(t_program *program);
void 	ft_moveleft(t_program *program);
void 	ft_moveright(t_program *program);
void	ft_check_map(t_program *program);
void	ft_extract_map(char *av, t_program *program);
void 	ft_form_check(t_program *program);
void 	ft_walls_check(t_program *program);
void 	ft_check_ber(char *av);
void	ft_free_alloc(t_program *program, int z);
void	ft_draw_map(t_program *program);
void	ft_draw_images(t_program *program);
int 	ft_hooked_func(int key, t_program *program);
int	    ft_timestamp_player(t_program *program);
void	ft_endgame(t_program *program);

#endif