#include "../includes/fractol.h"

int			key_handler(int k, t_mlx *m)
{
	if (k == 53)
		exit(0);
//	mlx_clear_window(m->mlx, m->win);
//	if (k == 0 || k == 1 || k == 2 || k == 6 || k == 7 || k == 8)
//		rotate(m, k, PI / 12);
//	if (k == 123 || k == 124 || k == 125 || k == 126)
//		shift(m, k, (int)WIN_W * 0.2);
//	if (k == 37 || k == 43 || k == 41 || k == 47 || k == 39 || k == 44)
//		stretch(m, k, 0.1);
//	if (k == 15)
//		setup(m);
//	draw(m);
	return (0);
}


void	setup(t_mlx *m)
{
	
}

int			main(int argc, char **argv)
{
	t_mlx	m;

	if (argc != 2)
		ft_errorexit("usage: ./fractol <Set Name>");
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "fdf");
	setup(&m);
	mlx_key_hook(m.win, key_handler, &m);
//	mlx_mouse_hook(m.win, mouse_handler, &m);
	draw(&m);
	mlx_loop(m.mlx);
	return (0);
}