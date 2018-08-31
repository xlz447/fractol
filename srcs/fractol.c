# include "../includes/fractol.h"

const int g_color[16] = 
{
	65536 * 66 + 256 * 30 + 15,
	65536 * 25 + 256 * 7 + 26,
	65536 * 9 + 256 * 1 + 47,
	65536 * 4 + 256 * 4 + 73,
	65536 * 0 + 256 * 7 + 100,
	65536 * 12 + 256 * 44 + 138,
	65536 * 24 + 256 * 82 + 177,
	65536 * 57 + 256 * 125 + 209,
	65536 * 134 + 256 * 181 + 229,
	65536 * 211 + 256 * 236 + 248,
	65536 * 241 + 256 * 233 + 191,
	65536 * 248 + 256 * 201 + 95,
	65536 * 255 + 256 * 170 + 0,
	65536 * 204 + 256 * 128 + 0,
	65536 * 153 + 256 * 87 + 0,
	65536 * 106 + 256 * 52 + 3
};

int		test_converge(t_mlx *m, float cur[2], float param[2])
{
	int		i;
	
	i = 0;
	while (i < m->mx_i && cur[0] * cur[0] + cur[1] * cur[1] <= m->mx_d)
	{
		cur[2] = cur[0] * cur[0] - cur[1] * cur[1] + param[0];
		cur[1] = 2 * cur[0] * cur[1] + param[1];
		cur[0] = cur[2];
		i++;
	}
	return (i);	
}

void	*draw_jul(void *ag)
{
	float	cur[3];		// cur z (real and imaginary) and tmp
	int		i;			// the cur iteration
	t_mlx	*m;
	int		cor[2];		// cur and init coordinates (x, y)

	m = (t_mlx *)ag;
	cor[1] = 0;
	while (cor[1] < WIN_H)
	{
		cor[0] = 0;
		while (cor[0] < WIN_W)
		{
			cur[0] = calc_cor(m, cor[0], 0);
			cur[1] = calc_cor(m, cor[1], 1);			
			i = test_converge(m, cur, m->init_c);
			if (i <= m->mx_i) // color
				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = g_color[i % 16];
			else
				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = 0;
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
	float	cur[3];		// cur z (real and imaginary) and tmp
	float	pxl_to_coor[2];
	int		i;			// the cur iteration
	t_mlx	*m;
	int		cor[2];		// cur and init coordinates (x, y)
	
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
			pxl_to_coor[0] = calc_cor(m, cor[0], 0);
			pxl_to_coor[1] = calc_cor(m, cor[1], 1);
			i = test_converge(m, cur, pxl_to_coor);
//			while (i++ < m->mx_i && cur[0] * cur[0] + cur[1] * cur[1] <= m->mx_d)
//			{
//				cur[2] = cur[0] * cur[0] - cur[1] * cur[1] + calc_cor(m, cor[0], 0);
//				cur[1] = 2 * cur[0] * cur[1] + calc_cor(m, cor[1], 1);
//				cur[0] = cur[2];
//			}		
			if (i <= m->mx_i) // color
				((unsigned int *)m->ad)[(cor[1] * WIN_W + cor[0])] = g_color[i % 16];
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
}
