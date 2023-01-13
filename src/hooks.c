#include "fractol.h"

int mouse_hook(int keycode, int x, int y, t_w *w)
{
	if (keycode == 5)
	{
		w->f.h /= 1.1;
		w->f.nx += 0.001 * ((x - w->f.w_len / 2) * (w->f.h));
		w->f.ny += 0.001 * ((y - w->f.w_len / 2) * (w->f.h));
		w->f.m *= 1.001;
        pick_f(w);
	}
	if (keycode == 4)
	{
		w->f.h *= 1.1;
		w->f.nx -= 0.001 * ((x - w->f.w_len / 2) * (w->f.h));
		w->f.ny -= 0.001 * ((y - w->f.w_len / 2) * (w->f.h));		
		w->f.m /= 1.001;
        pick_f(w);
	}
	if (keycode == 1)
	{
		w->f.h = 1;
		w->f.nx = 0;
		w->f.ny = 0;
		w->f.pos_x = 0;
		w->f.pos_y = 0;
        pick_f(w);
	}
	return (0);
}

void    pick_color(int keycode, t_w *w)
{
	if (keycode == 82)
	{
		w->f.colors = 0;
        pick_f(w);
	}
	if (keycode == KEY_ONE)
	{
		w->f.colors = 327700;
        pick_f(w);
	}
	if (keycode == KEY_TWO)
	{
		w->f.colors = 4850000;
        pick_f(w);
	}
	if (keycode == KEY_THREE)
	{
		w->f.colors = 832100;
        pick_f(w);
	}
}

void    julia_changes(int keycode, t_w *w)
{
    if (keycode == KEY_O)
	{
		w->f.p /= 1.001;
        pick_f(w);
	}
	if (keycode == KEY_I)
	{
		w->f.p *= 1.001;
        pick_f(w);
	}
}

void    frac_moove(int keycode, t_w *w)
{
	if(keycode == KEY_LEFT)
	{
		w->f.nx -= 0.1 * w->f.h ;
	    pick_f(w);
	}
	if (keycode == KEY_RIGHT)
	{
	    w->f.nx += 0.1 * w->f.h;
        pick_f(w);
	}
	if (keycode == KEY_DOWN)
	{
		w->f.ny -= 0.1 * w->f.h;
        pick_f(w);
	}
	if (keycode == KEY_UP)
	{
		w->f.ny += 0.1 * w->f.h;
        pick_f(w);
	}
}

int	key_hook(int keycode, t_w *w)
{
	if (keycode == KEY_PLUS)
	{
		w->f.h /= 1.1;
		w->f.m *= 1.001;
        pick_f(w);
	}
	if (keycode == KEY_MINUS)
	{
	    w->f.h *= 1.1;
	    w->f.m /= 1.001;
        pick_f(w);
	}
	if (keycode == KEY_P)
	{
		w->f.h = 1;
		w->f.nx = 0;
		w->f.ny = 0;
        pick_f(w);
	}
    frac_moove(keycode, w);
    julia_changes(keycode, w);
    pick_color(keycode, w);
	return (0);
}