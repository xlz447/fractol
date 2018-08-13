# include "../includes/fractol.h"

void	*draw_man(void *ag)
{
	double	cur[3];		// the current z (real and imaginary) and tmp
	int		i;			// the current iteration
	int		cor[4];		// curr and starting coordinates (x, y)
	t_mlx	*m;
	
	m = (t_mlx *)ag;
	cor[2] = (m->th_i % 2 != 0) ? WIN_W / 2: 0;
	cor[3] = (m->th_i / 2 != 0) ? WIN_H / 2: 0;
	cor[1] = cor[3];
	while (cor[1] < cor[3] + WIN_H / 2)
	{
		cor[0] = cor[2];
		while (cor[0] < cor[2] + WIN_W / 2)
		{
			i = -1;
			cur[0] = 0;
			cur[1] = 0;
			while (i++ < m->mx_i && pow(cur[0], 2) + pow(cur[1], 2) <= m->mx_d)
			{
				cur[2] = pow(cur[0], 2) - pow(cur[1], 2) + calc_cor(m, cor, 0);
				cur[1] = 2 * cur[0] * cur[1] + calc_cor(m, cor, 1);
				cur[0] = cur[2];
			}		
			if (i <= m->mx_i)
				mlx_pixel_put(m->mlx, m->win, cor[0], cor[1], col_code(i));
			cor[0]++;
		}
		cor[1]++;
	}
	return (NULL);
}

void	draw(t_mlx *m)
{
	pthread_t	th;
	int			i;
		
	ft_putstr("Start Drawing\n");
	i = 0;
	while (i < 4)
	{
		m->th_i = i;
		if(m->set_mode == 0)
			pthread_create(&th, NULL, draw_man, (void*)m);
		pthread_join(th, NULL);
		i++;
	}
	ft_putstr("Done Drawing\n");
}
