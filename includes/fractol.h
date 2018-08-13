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


#include <stdio.h>




# define WIN_H 600
# define WIN_W 600

typedef struct	s_img
{

}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			b_p_p; // 1 byte per pix for RGB
	int			s_l; // 1 byte * WIN_W
	int			end; // endian
	char		*ad; // char * of the image
	int			num_img;  // we can have mult. img in the future
	float		scale[2]; // x, y scale
	int			set_mode; // 0 for Mandelbrot set
	float		x_mnmx[2];
	float		y_mnmx[2];
	int			mx_i;
	float		mx_d;
	char		th_i;
}				t_mlx;


void			draw(t_mlx *m);
int				col_code(int iter);
float			calc_cor(t_mlx *m, int cor[2], int mode);
# endif