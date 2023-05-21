
#include "so_long.h"

//Se non é rettangolare
void ft_form_check(t_program *program)
{
    int l;
    int len;
    int len2;

    l = 1;
    len = program->map_width;
    while (program->map[l])
	{
        len2 = ft_strlen(program->map[l]);
        if (len == len2)
            l++;
        else
            ft_free_alloc(program, 0);
	}
}

//Se non é chiusa/circondata da muri
void ft_walls_check(t_program *program)
{  
    int i;

    i = 0;
    while (i < program->map_height)
	{
		if (program->map[i][0] == '1' && program->map[i][program->map_width - 1] == '1')
			i++;
		else
			ft_free_alloc(program, 1);
	}
	i = 0;
	while (i < program->map_width)
	{
		if (program->map[0][i] == '1' && program->map[program->map_height - 1][i] == '1')
			i++;
		else
			ft_free_alloc(program, 1);
	}
}

//Se la mappa non é un .ber
void ft_check_ber(char *av)
{
	int l;

    l = ft_strlen(av);
	if (!(av[l - 1] == 'r' && av[l - 2] == 'e' && av[l - 3] == 'b'
        && av[l - 4] == '.'))
	{
		ft_printf("Errore: la mappa deve essere in formato .ber\n");
		exit(0);
	}
}

//Se errore, libera la memoria e restituisce un messaggio in base all'errore 
void	ft_free_alloc(t_program *program, int z)
{
	int	i;

	i = 0;
	while (program->map[i])
	{
		free(program->map[i]);
		i++;
	}
	free(program->map[i]);
	free(program->map);
	if (z == 2)
		ft_printf("Errore: La mappa non possiede tutti gli elementi necessari");
	if (z == 1)
		ft_printf("Errore: La mappa deve essere chiusa.\n");
	if (z == 0)
		ft_printf("Errore: La mappa non é rettangolare.\n");
	exit(0);
}

// Se la mappa non ha tutti gli elementi giusti
void	ft_check_elements(t_program *program)
{
	int	i;
	int	j;
	int	pla;
	int	ex;

	i = 0;
	pla = 0;
	ex = 0;
	while  (program->map[i])
	{
		j = 0;
		while (program->map[i][j])
		{
			if (program->map[i][j] == 'P')
			{
				pla++;
				program->player_y = i;
				program->player_x = j;				
			}
			if (program->map[i][j] == 'E')
			{
				ex++;
			}
			if (program->map[i][j] == 'C')
			{
				program->collectibles++;
			}
			j++;
		}
	i++;
	}
	if (pla == 0 || ex == 0)
		ft_free_alloc(program, 2);
}

void	ft_check_map(t_program *program)
{
    ft_form_check(program);
    ft_walls_check(program);
	ft_check_elements(program);
}