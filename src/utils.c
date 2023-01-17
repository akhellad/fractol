/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:54:32 by akhellad          #+#    #+#             */
/*   Updated: 2023/01/17 13:54:53 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i ++;
		else
			return (1);
	}
	return (0);
}

int	destroy_window(t_w *w)
{
	mlx_destroy_window(w->mlx, w->mlx_w);
	exit(1);
}

void	stop_prog(int keycode, t_w *w)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(w->mlx, w->mlx_w);
		exit(1);
	}
}

void	reset_frac(t_w *w)
{
	w->f.h = 1;
	w->f.nx = 0;
	w->f.ny = 0;
	w->f.pos_x = 0;
	w->f.pos_y = 0;
	pick_f(w);
}

void	pick_f(t_w *w)
{
	if (!ft_strcmp(w->f.name, "mendel"))
		mendel(w);
	if (!ft_strcmp(w->f.name, "julia"))
		julia(w);
	if (!ft_strcmp(w->f.name, "burning_ship"))
		burning_ship(w);
}
