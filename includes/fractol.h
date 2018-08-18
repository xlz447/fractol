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

// -----------------
#include <stdio.h>
// -----------------

# define WIN_H 600
# define WIN_W 600

typedef struct	s_mlx // if we want to do mult. image, we might need a struct
{
	void		*mlx; // mlx ptr
	void		*win; // window ptr
	void		*img; // image ptr
	int			b_p_p; // 1 byte per pix for RGB
	int			s_l; // 1 byte * WIN_W
	int			end; // endian
	char		*ad; // char * of the image
	float		scale[2]; // x, y scale
	int			set_mode; // 0 for Mandelbrot 1 for Julia
	float		xy_mnmx[4]; // x min max y min max
	int			mx_i;	// max iteration
	float		mx_d;	// max distance
	char		th_i;	// thread index
	float		init_c[2]; // the constant used in julia (change by arrow position)
	int			mouse[2];
	char		hold;	// this allows user to hold the constant for julia
}				t_mlx;


void			draw(t_mlx *m);
int				col_code(int iter);
float			calc_cor(t_mlx *m, int cor, int mode);
void			shift(int k, t_mlx *m, float scale);
# endif