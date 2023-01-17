/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:37:38 by akhellad          #+#    #+#             */
/*   Updated: 2023/01/17 17:14:59 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlxinit(t_w *w)
{
	w->mlx = mlx_init();
	w->mlx_w = mlx_new_window(w->mlx, w->f.w_len, w->f.w_len, "first w");
	w->img1.img = mlx_new_image(w->mlx, w->f.w_len, w->f.w_len);
	w->img1.addr = mlx_get_data_addr(w->img1.img, &w->img1.bits_per_pixel, \
									&w->img1.line_length, &w->img1.endian);
}

void	init_struct(t_w *w)
{
	w->f.h = 1;
	w->f.p = 1;
	w->f.m = 1;
	w->f.pos_x = 0;
	w->f.pos_y = 0;
	w->f.w_len = 700;
	w->f.j = 1;
	mlxinit(w);
}

int	check_params(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "Erreur ! Veuillez choisir entre la fractale :\n \
mendel, julia ou burning_ship.\n", 78);
		return (1);
	}
	if (ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mendel") && \
									ft_strcmp(av[1], "burning_ship"))
	{
		write(1, "Erreur ! Veuillez choisir entre la fractale :\n \
mendel, julia ou burning_ship.\n", 78);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_w	w;

	if (check_params(argc, argv))
		return (0);
	w.f.name = argv[1];
	init_struct(&w);
	if (!ft_strcmp(w.f.name, "julia"))
		mlx_hook(w.mlx_w, 6, (1L << 6), mouse_motion_hook, &w);
	mlx_mouse_hook(w.mlx_w, mouse_hook, &w);
	mlx_hook(w.mlx_w, 2, 1L << 0, key_hook, &w);
	mlx_hook(w.mlx_w, ON_DESTROY, 0L, destroy_window, &w);
	mlx_loop(w.mlx);
}
