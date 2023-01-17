/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:43:08 by akhellad          #+#    #+#             */
/*   Updated: 2023/01/17 17:13:36 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int keycode, int x, int y, t_w *w)
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
		reset_frac(w);
	}
	return (0);
}

void	pick_color_012(int keycode, t_w *w)
{
	if (keycode == 82)
	{
		w->f.colors_out = 0;
		w->f.colors_in = 0;
		pick_f(w);
	}
	if (keycode == KEY_ONE)
	{
		w->f.colors_out = 327700;
		w->f.colors_in = 0x3a5266;
		pick_f(w);
	}
	if (keycode == KEY_TWO)
	{
		w->f.colors_out = 0x10182e;
		w->f.colors_in = 0x0c1023;
		pick_f(w);
	}
}

void	pick_color_345(int keycode, t_w *w)
{
	if (keycode == KEY_THREE)
	{
		w->f.colors_out = 0x8d697a;
		w->f.colors_in = 0x544e68;
		pick_f(w);
	}
	if (keycode == KEY_FOUR)
	{
		w->f.colors_out = 0x408898;
		w->f.colors_in = 0x1c1a3a;
		pick_f(w);
	}
	if (keycode == KEY_FIVE)
	{
		w->f.colors_out = 64176229;
		pick_f(w);
	}
}

void	frac_moove(int keycode, t_w *w)
{
	if (keycode == KEY_LEFT)
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
		reset_frac(w);
		pick_f(w);
	}
	stop_prog(keycode, w);
	frac_moove(keycode, w);
	julia_changes(keycode, w);
	pick_color(keycode, w);
	return (0);
}
