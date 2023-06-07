#ifndef TYPES_H
# define TYPES_H

//struct
typedef enum s_bool
{
	TRUE=1;
	FALSE=0
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

typedef struct s_enemy
{
	int	dir;
    char *en_type;
	int posx;
	int posy;
}t_enemy;

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
	t_enemy		enemy_hor;
	t_enemy		enemy_vert;
	t_enemy		enemy_foll;
}	t_program;

#endif

