#include "../includes/fractol.h"

int			key_handler(int k, t_mlx *m)
{
	if (k == 53)
		exit(0);
	else
	{
		mlx_destroy_image(m->mlx, m->img);
		if (k == 24)
		{		
			m->scale[0] /= 5;
			m->scale[1] /= 5;			
		}
		draw(m);
	}
	return (0);
}

void	setup(t_mlx *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_W, WIN_H, "fractol");
	m->mx_i = 1000;
	m->mx_d = 4;			// 2 ^ 2
	m->x_mnmx[0] = -3;	// x min
	m->x_mnmx[1] = 1;		// x max
	m->y_mnmx[0] = -1.5;		// y min
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
//	mlx_mouse_hook(m.win, mouse_handler, &m);
	mlx_loop(m.mlx);
	return (0);
}