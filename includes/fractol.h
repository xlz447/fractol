# ifndef FRACTOL_H
#define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define WIN_H 600
# define WIN_W 600

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	float		scale;
	int			set_mode; // 0 for Mandelbrot set
	float		x_mnmx[2];
	float		y_mnmx[2];
	int			shift[2]; // xy shift (for bonus: zoom follow arrow)
	int			mx_i;
	float		mx_d;
	char		th_i;
}				t_mlx;

void			draw(t_mlx *m);
int				col_code(int iter);
float			calc_cor(t_mlx *m, int cor[2], int mode);
# endif