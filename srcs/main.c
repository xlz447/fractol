#include "../includes/fractol.h"

int			mouse_handler(int b,int x,int y, t_mlx *m)
{
	float	x_mid;
	float	y_mid;
	float	n_mid[2];
	int		t_mid[2];
	
	mlx_destroy_image(m->mlx, m->img);
	t_mid[0] = x;
	t_mid[1] = y;
	n_mid[0] = calc_cor(m, t_mid, 0);
	n_mid[1] = calc_cor(m, t_mid, 1);	
	x_mid = (m->x_mnmx[1] + m->x_mnmx[0]) / 2;
	y_mid = (m->y_mnmx[1] + m->y_mnmx[0]) / 2;	
	m->x_mnmx[0] -= (x_mid - n_mid[0]);
	m->x_mnmx[1] -= (x_mid - n_mid[0]);
	m->y_mnmx[0] -= (y_mid - n_mid[1]);
	m->y_mnmx[1] -= (y_mid - n_mid[1]);
	draw(m);
	return (0);
}

int			key_handler(int k, t_mlx *m)
{
	ft_putnbr(k);
	ft_putchar('\n');
	if (k == 53)
		exit(0);
	else if (k == 24 ||  k == 27 || (k >= 123 && k <= 126) || k == 12 || k == 13)
	{
		mlx_destroy_image(m->mlx, m->img);
		if (k == 24 || k == 27)
		{		
			m->scale[0] = m->scale[0] / ((k == 24) ? 5 : 0.2);
			m->scale[1] = m->scale[1] / ((k == 24) ? 5 : 0.2);
		}
		else if (k >= 123 && k <= 126)
			shift(k, m, 0.1);
		else if (k == 12 || k == 13)
		{
			m->mx_i = m->mx_i * round((k % 2) ? 0.5 : 2);
			m->mx_i = (m->mx_i) ? m->mx_i : 1;
		}
		draw(m);
	}
	return (0);
}

void	setup(t_mlx *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_W, WIN_H, "fractol");
	m->mx_i = 100;
	m->mx_d = 16;
	m->x_mnmx[0] = -3;		// x min
	m->x_mnmx[1] = 1;		// x max
	m->y_mnmx[0] = -1.5;	// y min
	m->y_mnmx[1] = 1.5;		// y max
	m->scale[0] = (m->x_mnmx[1] - m->x_mnmx[0]) / WIN_W;
	m->scale[1] = (m->y_mnmx[1] - m->y_mnmx[0]) / WIN_H;
}

int			main(int argc, char **argv)
{
	t_mlx	m;

	if (argc != 2)
		ft_errorexit("usage: ./fractol <Set Name>");
	if (!strcmp(argv[1], "Mandelbrot"))
		m.set_mode = 0;
	//else if ...
	else
		ft_errorexit("valid set names: Mandelbrot, ...");
	setup(&m);
	draw(&m);
	mlx_key_hook(m.win, key_handler, &m);
	mlx_mouse_hook(m.win, mouse_handler, &m);
	mlx_loop(m.mlx);
	return (0);
}