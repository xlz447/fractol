# include "../includes/fractol.h"

void	*draw_jul(void *ag)
{
	double	cur[3];		// cur z (real and imaginary) and tmp
	int		i;			// the cur iteration
//	int		cor[4];		// cur and init coordinates (x, y)
	t_mlx	*m;
	int		cor[2];
	
	m = (t_mlx *)ag;
	cor[1] = 0;
	while (cor[1] < WIN_H)
	{
		cor[0] = 0;
		while (cor[0] < WIN_W)
		{
			i = -1;
			cur[0] = calc_cor(m, cor[0], 0);
			cur[1] = calc_cor(m, cor[1], 1);
			while (i++ < m->mx_i && pow(cur[0], 2) + pow(cur[1], 2) <= m->mx_d)
			{
				cur[2] = pow(cur[0], 2) - pow(cur[1], 2) + m->init_c[0];
				cur[1] = 2 * cur[0] * cur[1] + m->init_c[1];
				cur[0] = cur[2];
			}		
			if (i <= m->mx_i) // color
				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = mlx_get_color_value (m->mlx, col_code(i));
			//mlx_pixel_put(m->mlx, m->win, cor[0], cor[1], col_code(i)); <- in case of stuff not working lol			
			else
				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = mlx_get_color_value (m->mlx, 0);
			cor[0]++;
		}
		cor[1]++;
	}
//	m = (t_mlx *)ag;
//	cor[2] = (m->th_i % 2 != 0) ? WIN_W / 2: 0;
//	cor[3] = (m->th_i / 2 != 0) ? WIN_H / 2: 0;
//	cor[1] = cor[3];
//	while (cor[1] < cor[3] + WIN_H / 2)
//	{
//		cor[0] = cor[2];
//		while (cor[0] < cor[2] + WIN_W / 2)
//		{
//			i = -1;
//			cur[0] = calc_cor(m, cor[0], 0);
//			cur[1] = calc_cor(m, cor[1], 1);
//			while (i++ < m->mx_i && pow(cur[0], 2) + pow(cur[1], 2) <= m->mx_d)
//			{
//				cur[2] = pow(cur[0], 2) - pow(cur[1], 2) + m->init_c[0];
//				cur[1] = 2 * cur[0] * cur[1] + m->init_c[1];
//				cur[0] = cur[2];
//			}		
//			if (i <= m->mx_i) // color
//				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = mlx_get_color_value (m->mlx, col_code(i));
//			//mlx_pixel_put(m->mlx, m->win, cor[0], cor[1], col_code(i)); <- in case of stuff not working lol			
//			else
//				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = mlx_get_color_value (m->mlx, 0);
//			cor[0]++;
//		}
//		cor[1]++;
//	}
	return (NULL);
}

void	*draw_man(void *ag)
{
	double	cur[3];		// cur z (real and imaginary) and tmp
	int		i;			// the cur iteration
//	int		cor[4];		// cur and init coordinates (x, y)
	t_mlx	*m;
	int		cor[2];
	
	m = (t_mlx *)ag;
	cor[1] = 0; // y
	while (cor[1] < WIN_H)
	{
		cor[0] = 0; // x
		while (cor[0] < WIN_W)
		{
			i = -1;
			cur[0] = 0;
			cur[1] = 0;
			while (i++ < m->mx_i && pow(cur[0], 2) + pow(cur[1], 2) <= m->mx_d)
			{
				cur[2] = pow(cur[0], 2) - pow(cur[1], 2) + calc_cor(m, cor[0], 0);
				cur[1] = 2 * cur[0] * cur[1] + calc_cor(m, cor[1], 1);
				cur[0] = cur[2];
			}		
			if (i <= m->mx_i) // color
				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = mlx_get_color_value (m->mlx, col_code(i));
			//mlx_pixel_put(m->mlx, m->win, cor[0], cor[1], col_code(i)); <- in case of stuff not working lol			
			else
				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = mlx_get_color_value (m->mlx, 0);
			cor[0]++;
		}
		cor[1]++;
	}
//		cor[2] = (m->th_i % 2 != 0) ? WIN_W / 2: 0;
//	cor[3] = (m->th_i / 2 != 0) ? WIN_H / 2: 0;
//	cor[1] = cor[3];
//	while (cor[1] < cor[3] + WIN_H / 2)
//	{
//		cor[0] = cor[2];
//		while (cor[0] < cor[2] + WIN_W / 2)
//		{
//			i = -1;
//			cur[0] = 0;
//			cur[1] = 0;
//			while (i++ < m->mx_i && pow(cur[0], 2) + pow(cur[1], 2) <= m->mx_d)
//			{
//				cur[2] = pow(cur[0], 2) - pow(cur[1], 2) + calc_cor(m, cor[0], 0);
//				cur[1] = 2 * cur[0] * cur[1] + calc_cor(m, cor[1], 1);
//				cur[0] = cur[2];
//			}		
//			if (i <= m->mx_i) // color
//				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = mlx_get_color_value (m->mlx, col_code(i));
//			//mlx_pixel_put(m->mlx, m->win, cor[0], cor[1], col_code(i)); <- in case of stuff not working lol			
//			else
//				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = mlx_get_color_value (m->mlx, 0);
//			cor[0]++;
//		}
//		cor[1]++;
//	}

	return (NULL);
}

void	draw(t_mlx *m)
{
//	pthread_t	th;
//	int			i;
		

	ft_putstr("Start Drawing\n");
//	i = 0;
	if(m->set_mode == 0)
		draw_man((void*)m);
	else if(m->set_mode == 1)
		draw_jul((void*)m);
//	while (i < 4)
//	{
//		m->th_i = i;
//		if(m->set_mode == 0)
//			pthread_create(&th, NULL, draw_man, (void*)m);
//		else if(m->set_mode == 1)
//			pthread_create(&th, NULL, draw_jul, (void*)m);
//		pthread_join(th, NULL);
//		i++;
//	}
	mlx_put_image_to_window (m->mlx, m->win, m->img, 0, 0);
	ft_putstr("Done Drawing\n");
}
