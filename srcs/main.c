#include "../includes/fractol.h"

int			key_handler(int k, t_mlx *m)
{
	if (k == 53)
		exit(0);
//	mlx_clear_window(m->mlx, m->win);
//	if (k == 15)
//		setup(m);
//	draw(m);
	return (0);
}


void	setup(t_mlx *m, char *mode)
{
	if (!strcmp(mode, "Mandelbrot"))
		m->set_mode = 0;
	//else if ...
	else
		ft_errorexit("valid set names: Mandelbrot, ...");
	m->init_rl = 0; // might have to change by case later
	m->init_img = 0;
	m->max_iter = 1000;
	m->max_dis = 50000000000;
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