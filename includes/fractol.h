# ifndef FRACTOL_H
#define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define WIN_H 400
# define WIN_W 600
# define PI 3.14159265



typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	float		scale;
	int			set_mode; // 0 for Mandelbrot set
	float		init_rl;
	float		init_img;
	int			max_iter;
	float		max_dis;
}				t_mlx;

void			draw(t_mlx *m);
# endif