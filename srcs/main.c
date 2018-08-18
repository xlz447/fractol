#include "../includes/fractol.h"

int			mouse_move(int x, int y, t_mlx *m)
{
	m->mouse[0] = x;
	m->mouse[1] = y;
	if (m->set_mode == 1 && !m->hold)
	{
		mlx_destroy_image(m->mlx, m->img);
		m->init_c[0] = calc_cor(m, x, 0);
		m->init_c[1] = calc_cor(m, y, 1);;
		draw(m);
	}
	return (0);
}

int			mouse_handler(int b,int x,int y, t_mlx *m)
{
	float	x_mid;
	float	y_mid;
	float	n_mid[2];
	
	if (b != 42)
		mlx_destroy_image(m->mlx, m->img);
	n_mid[0] = calc_cor(m, x, 0);
	n_mid[1] = calc_cor(m, y, 1);	
	x_mid = (m->xy_mnmx[0] + m->xy_mnmx[1]) / 2;
	y_mid = (m->xy_mnmx[2] + m->xy_mnmx[3]) / 2;	
	m->xy_mnmx[0] -= (x_mid - n_mid[0]);
	m->xy_mnmx[1] -= (x_mid - n_mid[0]);
	m->xy_mnmx[2] -= (y_mid - n_mid[1]);
	m->xy_mnmx[3] -= (y_mid - n_mid[1]);
	if (b != 42)
		draw(m);
	return (0);
}

int			key_handler(int k, t_mlx *m)
{
	ft_putnbr(k);
	ft_putchar('\n');
	if (k == 53)
		exit(0);
	else if (k == 4 || k == 24 || k == 27 || (k >= 123 && k <= 126) || k == 12 || k == 13)
	{
		mlx_destroy_image(m->mlx, m->img);
		if (k == 4)
			m->hold = !m->hold;
		else if (k == 24 || k == 27)
		{
			if (m->set_mode == 0 || (m->set_mode == 1 && m->hold))
				mouse_handler(42, m->mouse[0], m->mouse[1], m);	
			m->scale[0] = m->scale[0] / ((k == 24) ? 5 : 0.2);
			m->scale[1] = m->scale[1] / ((k == 24) ? 5 : 0.2);
		}
		else if (k >= 123 && k <= 126)
			shift(k, m, 0.1);
		else if (k == 12 || k == 13)
		{
			m->mx_i = round((float)m->mx_i * ((k % 2) ? 0.5 : 2));
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
	m->mx_d = 4;
	m->xy_mnmx[0] = -2.5;		// x min
	m->xy_mnmx[1] = 1;		// x max
	m->xy_mnmx[2] = -1;	// y min
	m->xy_mnmx[3] = 1;		// y max
	m->scale[0] = (m->xy_mnmx[1] - m->xy_mnmx[0]) / WIN_W;
	m->scale[1] = (m->xy_mnmx[3] - m->xy_mnmx[2]) / WIN_H;
	m->init_c[0] = 0;
	m->init_c[1] = 0;
	m->mouse[0] = 0;
	m->mouse[1] = 0;
	m->hold = 0;
}

int			main(int argc, char **argv)
	// if we want to make multiple windows, we will need multithreading on each of the windows (because of the loop hanging there)
{
	t_mlx	m;

	if (argc != 2)
		ft_errorexit("usage: ./fractol <Set Name>");
	if (!strcmp(argv[1], "Mandelbrot"))
		m.set_mode = 0;
	else if (!strcmp(argv[1], "Julia"))
		m.set_mode = 1;
	else
		ft_errorexit("valid set names: Mandelbrot, Julia");
	setup(&m);
	draw(&m);
	mlx_key_hook(m.win, key_handler, &m);
	mlx_mouse_hook(m.win, mouse_handler, &m);
	mlx_hook(m.win, 6, 0, mouse_move, &m);
	mlx_loop(m.mlx);
	return (0);
}