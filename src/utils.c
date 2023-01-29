#include "../includes/fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putendl(char const *s)
{
	write(1, s, ft_strlen(s));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

void	*ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		n--;
		((unsigned char *)s)[n] = 0;
	}
	return (s);
}

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = (NULL);
}

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}
