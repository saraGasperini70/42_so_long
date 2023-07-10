/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:38:00 by sgasperi          #+#    #+#             */
/*   Updated: 2023/05/25 12:07:03 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "includes/get_next_line.h"
# include "includes/types.h"
# include "includes/enums.h"
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include "libs/mlx/mlx.h"

int		ft_exit(t_program *program);
void	ft_moveup(t_program *program);
void	ft_movedown(t_program *program);
void	ft_moveleft(t_program *program);
void	ft_moveright(t_program *program);
void	ft_check_map(t_program *program);
void	ft_extract_map(char *av, t_program *program);
void	ft_form_check(t_program *program);
void	ft_walls_check(t_program *program);
void	ft_check_ber(char *av);
void	ft_free_alloc(t_program *program, int z);
void	ft_draw_map(t_program *program);
void	ft_draw_images(t_program *program);
int		ft_hooked_func(int key, t_program *program);
int		ft_timestamp_player(t_program *program);
void	ft_endgame(t_program *program);
int		ft_timestamp_enemy_s(t_program *program);
int		ft_timestamp_enemy_m(t_program *program);
int		ft_timestamp_enemy_l(t_program *program);

#endif
