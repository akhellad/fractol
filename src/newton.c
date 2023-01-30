#include "../includes/fractol.h"

t_pixel newton_set(int x, int y, t_param *v, t_mlx *mlx)
{
t_complex z;
t_complex temp;
double x2;
double y2;
double x4;
double y4;
double x3y2;
double x2y4;
int i;

(void)mlx;
z = convert(x, y, v);
i = 0;
x2 = z.r * z.r;
y2 = z.i * z.i;
x4 = x2 * x2;
y4 = y2 * y2;
x3y2 = 3 * x2 * y2;
x2y4 = x2 * y4;
while (i < v->max)
{
	temp.r = (2 * x4 * z.r + 4 * x3y2 * z.r + x2 + 2 * x2y4 - y2)/(3 * (x2 + y2) * (x2 + y2));
	temp.i = (2 * z.i * y2 * (x4 + 2 * x2 * y2 - z.r + y4))/(3 * (x2 + y2) * (x2 + y2));
	if (fabs(z.r - temp.r) < 0.001 && fabs(z.i - temp.i) < 0.001)
		break ;
	
	i++;
}
return ((t_pixel){.c = z, .i = i});
}

void newton_param(t_param *v)
{
v->xmin = -2.0f;
v->xmax = 2.0f;
v->ymin = -2.0f;
v->ymax = 2.0f;
v->offx = -0.5f;
}