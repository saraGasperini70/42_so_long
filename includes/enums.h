#ifndef SO_LONG_H
# define SO_LONG_H

enum e_keys
{
	KEY_UP=13,
	KEY_DOWN=1,
	KEY_LEFT=0,
	KEY_RIGHT=2,
	KEY_ESC=53,
};

enum e_tilesize
{
	SIZE_X=64,
	SIZE_Y=64,
};

enum e_enemy_type
{
    HORIZONTAL=H,
    VERTICAL=V,
    FOLLOWER=F,
};

#endif