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

# define WIN_H 500
# define WIN_W 500
# define PI 3.14159265



typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	float		scale;
	int			set_mode; // 0 for Mandelbrot set
	float		x_mnmx[2];
	float		y_mnmx[2];
	int			shift[2]; // xy shift (for bonus: zoom follow arrow)
	int			max_iter;
	float		max_dis;
}				t_mlx;

void			draw(t_mlx *m);
# endif