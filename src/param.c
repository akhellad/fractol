#include "../includes/fractol.h"

void		param_fit(t_param *p)
{
	double w;
	double h;

	w = p->xmax - p->xmin;
	h = p->ymax - p->ymin;
	if (w / h >= (float)WIN_WIDTH / WIN_HEIGHT)
	{
		p->ymin = -(w * WIN_HEIGHT / WIN_WIDTH / 2);
		p->ymax = w * WIN_HEIGHT / WIN_WIDTH / 2;
	}
	else
	{
		p->xmin = -(h * WIN_WIDTH / WIN_HEIGHT / 2);
		p->xmax = (h * WIN_WIDTH / WIN_HEIGHT / 2);
	}
}

void		reset_param(t_mlx *mlx)
{
	mlx->param.offx = 0;
	mlx->param.offy = 0;
	mlx->fr->param(&mlx->param);
	param_fit(&mlx->param);
	mlx->param.max = 32;
	mlx->param.zoom = 1.0f;
}

t_complex	convert(int x, int y, t_param *v)
{
	t_complex	p;

	p.r = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	p.i = (((double)y / WIN_HEIGHT) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (p);
}

