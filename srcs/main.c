/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 22:52:42 by xzhu              #+#    #+#             */
/*   Updated: 2018/08/30 22:52:44 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_move(int x, int y, t_mlx *m)
{
	m->mouse[0] = x;
	m->mouse[1] = y;
	if (m->set_mode == 1 && !m->hold)
	{
		m->init_c[0] = calc_cor(m, x, 0);
		m->init_c[1] = calc_cor(m, y, 1);
		draw(m);
	}
	return (0);
}

int		mouse_handler(int b, int x, int y, t_mlx *m)
{
	float	x_mid;
	float	y_mid;
	float	n_mid[2];

	// ft_putnbr(b);
	// ft_putchar('\n');
	if (b == 4 || b == 5)
	{
		m->scale[0] = m->scale[0] / ((b == 4) ? 1.5 : 0.9);
		m->scale[1] = m->scale[1] / ((b == 4) ? 1.5 : 0.9);
	}
	n_mid[0] = calc_cor(m, x, 0);
	n_mid[1] = calc_cor(m, y, 1);
	x_mid = (m->xy_mnmx[0] + m->xy_mnmx[1]) / 2;
	y_mid = (m->xy_mnmx[2] + m->xy_mnmx[3]) / 2;
	m->xy_mnmx[0] -= (x_mid - n_mid[0]);
	m->xy_mnmx[1] -= (x_mid - n_mid[0]);
	m->xy_mnmx[2] -= (y_mid - n_mid[1]);
	m->xy_mnmx[3] -= (y_mid - n_mid[1]);
	draw(m);
	return (0);
}

void	setup(t_mlx *m)
{
	m->mx_i = 50;
	m->mx_d = 4;
	m->xy_mnmx[0] = -2;
	m->xy_mnmx[1] = 2;
	m->xy_mnmx[2] = -2;
	m->xy_mnmx[3] = 2;
	m->scale[0] = (m->xy_mnmx[1] - m->xy_mnmx[0]) / WIN_W;
	m->scale[1] = (m->xy_mnmx[3] - m->xy_mnmx[2]) / WIN_H;
	m->init_c[0] = 0;
	m->init_c[1] = 0;
	m->mouse[0] = 0;
	m->mouse[1] = 0;
	m->hold = 0;
	m->b_p_p = 8;
	m->s_l = 1 * WIN_W;
	m->end = 1;
	m->ad = mlx_get_data_addr(m->img, &(m->b_p_p), &(m->s_l), &(m->end));
}

int		key_handler(int k, t_mlx *m)
{
	ft_putnbr(k);
	ft_putchar('\n');
	if (k == 53)
		exit(0);
	else if (k == 4)
		m->hold = !m->hold;
	else if (k == 15)
		setup(m);
	else if (k >= 123 && k <= 126)
		shift(k, m, 0.1);
	else if (k == 69 || k == 78)
		m->mx_i = k == 78 ? m->mx_i - 5 : m->mx_i + 5;
	else if (k == 29)
		m->set_mode = 0;
	else if (k == 18)
		m->set_mode = 1;
	else if (k == 19)
		m->set_mode = 2;
	else if (k == 20)
		m->set_mode = 3;
	else if (k == 21)
		m->set_mode = 4;
	else if (k == 23)
		m->set_mode = 5;
	draw(m);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	m;

	if (argc != 2)
		ft_errorexit("usage: ./fractol <Mandelbrot, Julia, Ship>");
	if (!strcmp(argv[1], "Mandelbrot"))
		m.set_mode = 0;
	else if (!strcmp(argv[1], "Julia"))
		m.set_mode = 1;
	else if (!strcmp(argv[1], "Ship"))
		m.set_mode = 2;
	else if (!strcmp(argv[1], "Tricorn"))
		m.set_mode = 3;
	else if (!strcmp(argv[1], "Lauren"))
		m.set_mode = 4;
	else if (!strcmp(argv[1], "Qualslash"))
		m.set_mode = 5;
	else
		ft_errorexit("valid set names: Mandelbrot, Julia");
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "fractol");
	m.img = mlx_new_image(m.mlx, WIN_W, WIN_H);
	setup(&m);
	draw(&m);
	mlx_key_hook(m.win, key_handler, &m);
	mlx_mouse_hook(m.win, mouse_handler, &m);
	mlx_hook(m.win, 6, 0, mouse_move, &m);
	mlx_loop(m.mlx);
	return (0);
}
