/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 00:40:15 by xzhu              #+#    #+#             */
/*   Updated: 2018/09/01 00:40:16 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define WIN_H 800
# define WIN_W 800

/*
** mlx -- mlx ptr
** win -- win ptr
** img -- img ptr
** bpp -- 1 byte per pix for RGB
** s_l -- 1 byte * WIN_W
** end -- endian
** ad -- char * of the image
** scale -- x, y scale
** set_mode -- which fractol to start darwing
** xy_mnmx -- x min max y min max
** mx_i -- max iteration
** mx_d -- max distance
** init_c -- the constant used in julia (change by arrow position)
** mouse -- current mouse position
** hold -- hold current img for julia
** color_index -- index of which color set to use
** color -- rgb value of current color set
*/

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			b_p_p;
	int			s_l;
	int			end;
	char		*ad;
	double		scale[2];
	int			set_mode;
	double		xy_mnmx[4];
	int			mx_i;
	double		mx_d;
	double		init_c[2];
	int			mouse[2];
	char		hold;
	int			color_index;
	const int	*color;
}				t_mlx;

void			setup(t_mlx *m);
void			draw(t_mlx *m);
double			calc_cor(t_mlx *m, int cor, int mode);
void			shift(int k, t_mlx *m, double scale);
int				qualslash_converge(t_mlx *m, int x, int y);
int				man_converge(t_mlx *m, int x, int y);
int				lauren_converge(t_mlx *m, int x, int y);
int				ship_converge(t_mlx *m, int x, int y);
int				julia_converge(t_mlx *m, int x, int y);
void			change_color(t_mlx *m);
void			print_instructions(t_mlx *m);
int				dispatch(t_mlx *m, int x, int y);
int				test1_converge(t_mlx *m, int x, int y);
int				test2_converge(t_mlx *m, int x, int y);

#endif
