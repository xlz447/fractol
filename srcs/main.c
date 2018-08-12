#include "../includes/fractol.h"

int			key_handler(int k, t_mlx *m)
{
	if (k == 53)
		exit(0);
	else
	{
		mlx_clear_window(m->mlx, m->win);
		if (k == 24)
		{
			m->x_mnmx[0] /= 2;	// x min
			m->x_mnmx[1] /= 2;		// x max
			m->y_mnmx[0] /= 2;		// y min
			m->y_mnmx[1] /= 2;		// y max
		}
		draw(m);
	}
	return (0);
}


void	setup(t_mlx *m, char *mode)
{
	if (!strcmp(mode, "Mandelbrot"))
		m->set_mode = 0;
	//else if ...
	else
		ft_errorexit("valid set names: Mandelbrot, ...");
	m->max_iter = 1000;
	m->max_dis = 4;			// 2 ^ 2
	m->x_mnmx[0] = -2.5;	// x min
	m->x_mnmx[1] = 1;		// x max
	m->y_mnmx[0] = -1.5;		// y min
	m->y_mnmx[1] = 1.5;		// y max
	m->shift[0] = 0;
	m->shift[1] = 0;
}

int			main(int argc, char **argv)
{
	t_mlx	m;

	if (argc != 2)
		ft_errorexit("usage: ./fractol <Set Name>");
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "fdf");
	setup(&m, argv[1]);
	mlx_key_hook(m.win, key_handler, &m);
//	mlx_mouse_hook(m.win, mouse_handler, &m);
	draw(&m);
	mlx_loop(m.mlx);
	return (0);
}