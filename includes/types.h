/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:17:37 by sgasperi          #+#    #+#             */
/*   Updated: 2024/01/23 13:19:02 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

//struct
typedef enum s_bool
{
	TRUE=1,
	FALSE=0,
}	t_bool;

typedef struct s_image
{
	void	*wall;
	void	*player1;
	void	*enemy_hor;
	void	*enemy_ver;
	void	*enemy_fol;
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
	int			tstamp;
	int			loop;
	int			img_size;
	int			end_result;
}	t_program;

#endif
