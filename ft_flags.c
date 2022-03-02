/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/17 15:53:35 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ft_abs(long long a)
{
	return (a * ((a > 0) - (a < 0)));
}

static unsigned long	reverse_num(unsigned int a, int	*length)
{
	unsigned long	new_num;

	new_num = 0;
	*length = 0;
	while (a)
	{
		new_num = new_num * 10 + (a % 10);
		a /= 10;
		(*length)++;
	}
	return (new_num);
}

void	ft_count_num(int n, int *super_count, t_options *ops)
{
	unsigned long long	nn;
	int					length;

	nn = ft_abs((long long) n);
	if (ops->type == 'u')
		nn = (unsigned long) n;
	if (n == 0)
		(*super_count)++;
	if (n < 0 && ops->type != 'u')
		(*super_count)++;
	nn = reverse_num(nn, &length);
	while (length--)
	{
		(*super_count)++;
		nn /= 10;
	}
}

void	cons_flags(int *super_count, t_options *ops, void *t)
{
	if (ops->plus && (ops->type == 'd' || ops->type == 'i'))
	{
		if ((int)t >= 0)
		{
			write (1, "+", 1);
			(*super_count)++;
		}
	}
	if (ops->space && (ops->type == 'd' || ops->type == 'i'))
	{
		if ((int)t >= 0)
		{
			write (1, " ", 1);
			(*super_count)++;
		}
	}
	if ((int)t < 0)
	{
		write (1, "-", 1);
		(*super_count)++;
	}
}
