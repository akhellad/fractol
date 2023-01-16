#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_O 31
# define KEY_I 34
# define KEY_P 35
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_ONE 83
# define KEY_TWO 84
# define KEY_THREE 85
# define KEY_FOUR 86
# define KEY_FIVE 87
# define KEY_SIX 88
# define KEY_ESC 53

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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
void	mendel_calc(t_w *w);
void	burning_ship(t_w *w);
void	burning_ship_set(t_w *w);
void	julia_set(t_w *w);
void	stop_prog(int keycode, t_w *w);
int		destroy_window(t_w *w);
#endif