/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/16 20:43:17 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int	ft_abs(long long int num)
{
	return (num * ((num > 0) - (num < 0)));
}

static void	ft_str_rev(char *s)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		size;
	char				tmp;

	i = 0;
	size = ft_strlen(s);
	j = size - 1;
	while (i < size / 2)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

void	converter_big(void *t, int base, unsigned char **str)
{
	int	i;

	i = 0;
	*str = malloc(50);
	if (*str == 0)
		return ;
	if ((unsigned long long int)t < 0)
	{
		(*str)[i++] = '-';
		t = (void *)ft_abs((long long int)t);
	}
	if ((unsigned long long int)t == 0)
		(*str)[i++] = '0';
	while ((unsigned long long int)t)
	{
		if (((unsigned long long int)t % base) < 10)
			(*str)[i] = (((unsigned long long int)t % base) + 48);
		else
			(*str)[i] = (((unsigned long long int)t % base) + 55);
		t = (void *)((unsigned long long)t / 16);
		i++;
	}
	(*str)[i] = '\0';
	ft_str_rev((char *)(*str));
}

void	converter_small(void *t, int base, unsigned char **str)
{
	unsigned int	num;
	int				i;

	i = 0;
	*str = malloc(500);
	if (*str == 0)
		return ;
	num = ft_abs((unsigned int)t);
	if ((unsigned int)t < 0)
		(*str)[i++] = '-';
	if (num == 0)
		(*str)[i++] = '0';
	while (num)
	{
		if ((num % base) < 10)
			(*str)[i] = ((num % base) + 48);
		else
			(*str)[i] = ((num % base) + 55);
		num = (num / 16);
		i++;
	}
	(*str)[i] = '\0';
	ft_str_rev((char *)(*str));
}

char	*converter(void *t, int base, int big)
{
	unsigned char			*str;

	if (big)
		converter_big(t, base, &str);
	else
		converter_small(t, base, &str);
	return ((char *)str);
}
