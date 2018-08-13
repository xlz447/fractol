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
			m->x_mnmx[0] /= 4;	// x min
			m->x_mnmx[1] /= 4;		// x max
			m->y_mnmx[0] /= 4;		// y min
			m->y_mnmx[1] /= 4;		// y max
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
//	m->img = mlx_new_image (m->mlx, WIN_W, WIN_H);
	m->mx_i = 1000;
	m->mx_d = 4;			// 2 ^ 2
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
	m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "fractol");
	setup(&m, argv[1]);
	mlx_key_hook(m.win, key_handler, &m);
//	mlx_mouse_hook(m.win, mouse_handler, &m);
	draw(&m);
	mlx_loop(m.mlx);
	return (0);
}