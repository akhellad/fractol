#ifndef fTOL_H
# define fTOL_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_O 111
# define KEY_I 105
# define KEY_P 112
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_ONE 65436
# define KEY_TWO 65433
# define KEY_THREE 65435
# define KEY_FOUR 65430
# define KEY_FIVE 65437
# define KEY_SIX 65432
# define KEY_ESC 65307

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_jul 
{
	double	cx;
	double	cy;

}              t_jul;

typedef	struct s_f {
	double x1;
	double y1;
	double x2;
	double y2;
	double zx;
	double zy;
	double cx;
	double cy;
	double tempx;
	double image_x;
	double image_y;
	double zoom_x;
	double zoom_y;
	double pos_x;
	double pos_y;
	int x;
	int y;
	int count;
	int iteration_max;
	int w_len;
	double h;
	double p;
	double m;
	double nx;
	double ny; 
	char *name;
	int colors;
}			t_f;

typedef struct	s_w {
	void	*mlx;
	void	*mlx_w;
	t_data	img1;
	t_f		f;
	t_jul	j;
}				t_w;

int		ft_strcmp(char *s1, char *s2);
int		mouse_hook(int keycode, int x, int y, t_w *w);
void	pick_f(t_w *w);
void	julia(t_w *w);
void	mendel(t_w *w);
int		key_hook(int keycode, t_w *w);
void	count(t_w *w);
void	draw(t_w *w);
void    frac_moove(int keycode, t_w *w);
int 	mouse_motion_hook(int x, int y, t_w *w);
void	count_burning_ship(t_w *w);
int 	mouse_drag_hook(int x, int y, t_w *w);

#endif