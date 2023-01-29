#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "key.h"

# define WIN_WIDTH 400
# define WIN_HEIGHT 400
# define ZOOM 1.1f
# define THREADS 8

typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

typedef struct		s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}					t_palette;


typedef struct		s_complex
{
	double		r;
	double		i;
}					t_complex;

typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;

typedef struct		s_img
{
	void		*img;
	char		*adrr;
	int			bpp;
	int			lengh;
	int			endian;
}					t_img;

typedef struct		s_param
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
	double 		*coefs; 
	int 		degree;
	t_complex	mouse;
}					t_param;

typedef struct		s_pixel
{
	t_complex	c;
	long		i;
}					t_pixel;
typedef struct s_mlx	t_mlx;

typedef void		(*t_f_fn_v)(t_param *v);
typedef t_pixel		(*t_f_fn_p)(int x, int y, t_param *v, t_mlx *mlx);
typedef struct		s_fr
{
	char		*name;
	t_f_fn_v	param;
	t_f_fn_p	pixel;
	int			mouse;
}					t_fr;

typedef struct		s_thread
{
	int				id;
	t_mlx			*mlx;
}					t_thread;

typedef struct		s_render
{
	pthread_t		threads[THREADS];
	t_thread		args[THREADS];
}					t_render;

struct				s_mlx
{
	void		*mlx;
	void		*window;
	t_fr	    *fr;
	t_pixel		*data;
	t_img		*img;
	t_mouse		mouse;
	t_param	    param;
	t_palette	*palette;
	t_render	render;
	int			smooth;
	int			mouselock;
};


//main.c
int		    error(char *reason);

//mandelbrot.c
void		mandelbrot_param(t_param *v);
t_pixel		mandelbrot_set(int x, int y, t_param *v, t_mlx *mlx);

//fractal_set.c
t_fr	    *get_fractals(void);
t_fr	    *fractal_match(char *str);

//param.c
t_complex	convert(int x, int y, t_param *v);
void		reset_param(t_mlx *mlx);
void		param_fit(t_param *p);

//utils.c
int	        ft_strcmp(const char *s1, const char *s2);
void	    ft_putendl(char const *s);
size_t	    ft_strlen(const char *s);
void	    *ft_memalloc(size_t size);
void	    *ft_bzero(void *s, size_t n);
void	    ft_memdel(void **ap);
int		    ft_lerpi(int first, int second, double p);

//image.c
t_img	    *new_image(t_mlx *mlx);
t_img	    *del_image(t_mlx *mlx, t_img *img);
void	    my_mlx_pixel_put(t_img *data, int x, int y, int color);

//window.c
t_mlx		*mlx_del(t_mlx *mlx);
t_mlx		*init_mlx(t_fr *f);

//color.c
int			choose_color(t_pixel p, t_mlx *mlx);
t_color		smooth_color(t_pixel p, int max, t_palette *pal);
t_color		linear_color(double i, int max, t_palette *p);
t_color		clerp(t_color c1, t_color c2, double p);

//thread.c
void		render(t_mlx *mlx);
void		draw(t_mlx *mlx);
void		*apply_thread(void *m);

//julia.c
void		julia_param(t_param *v);
t_pixel		julia_set(int x, int y, t_param *v, t_mlx *mlx);
int		    julia_hook_mousemove(int x, int y, t_mlx *mlx);

//hook.c
int		    key_hook(int key, t_mlx *mlx);
void	    move(int key, t_mlx *mlx);
void		zoom(int x, int y, t_param *v, double z);
int		    mouse_hook(int button, int x, int y, t_mlx *mlx);
int			mouse_release_hook(int button, t_mlx *mlx);

//burning_ship.c
t_pixel		burningship_set(int x, int y, t_param *v, t_mlx *mlx);
void		burningship_param(t_param *v);

//palettes.c
t_palette	*get_palettes(void);
t_palette	*get_palettes2(void);
t_palette	*get_palettes3(void);
t_palette	*get_palettes4(void);

//sierpinski.c
void 		sierpinski_param(t_param *v);
t_pixel 	sierpinski_set(int x, int y, t_param *v, t_mlx *mlx);

#endif