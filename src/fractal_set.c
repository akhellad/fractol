#include "../includes/fractol.h"

t_fr	*get_fractals(void)
{
	static t_fr array[8] = {
		{"Mandel", mandelbrot_param, mandelbrot_set, 0},
		{"Julia", julia_param, julia_set, 1},
		{"Burning_ship", burningship_param, burningship_set, 0},
		{"Multibrot", Multibrot_param, Multibrot_set, 0},
		{"Newton", newton_param, newton_set, 0},
		{NULL, NULL, NULL, 0}
	};

	return (array);
}

t_fr	*fractal_match(char *str)
{
	t_fr	*fr;
	int			i;

	fr = get_fractals();
	i = 0;
	while (fr[i].name != NULL)
	{
		if (ft_strcmp(fr[i].name, str) == 0)
			return (&fr[i]);
		i++;
	}
	return (&fr[i]);
}
