/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:51:18 by akhellad          #+#    #+#             */
/*   Updated: 2023/01/30 12:02:38 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*copie;
	char	*src1;

	src1 = (char *)src;
	copie = malloc(ft_strlen(src1) + 1 * sizeof(char));
	if (!copie)
		return (0);
	copie = ft_strcpy(copie, src1);
	return (copie);
}

int	ft_countnbr(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i ++;
	}
	return (i);
}

char	*ft_itoa2(int n, char *str, int len, int i)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	i = len;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i --;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		len = ft_countnbr(n);
	else
		len = ft_countnbr(n) - 1;
	str = malloc(sizeof(char) * len + 2);
	if (!str)
		return (0);
	str = ft_itoa2(n, str, len, i);
	str[len + 1] = 0;
	return (str);
}
