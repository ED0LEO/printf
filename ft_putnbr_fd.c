/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/16 22:23:06 by mlothair         ###   ########.fr       */
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

void	ft_putnbr_dot(int n, int fd, int *super_count, t_options *ops)
{
	unsigned long long	nn;
	char				c;
	int					length;
	int					mw;

	mw = ops->mw;
	nn = ft_abs((long long) n);
	if (ops->type == 'u')
		nn = (unsigned long) n;
	if (n == 0)
	{
		(*super_count)++;
		write (fd, "0", 1);
		mw--;
	}
	nn = reverse_num(nn, &length);
	while (length--)
	{
		c = 48 + (nn % 10);
		write(fd, &c, 1);
		(*super_count)++;
		nn /= 10;
		mw--;
	}
}

void	ft_putnbr_fd(int n, int fd, int *super_count, t_options *ops)
{
	unsigned long long	nn;
	char				c;
	int					length;

	nn = ft_abs((long long) n);
	if (ops->type == 'u')
		nn = (unsigned long) n;
	if (n == 0)
	{
		(*super_count)++;
		write (fd, "0", 1);
	}
	nn = reverse_num(nn, &length);
	while (length--)
	{
		c = 48 + (nn % 10);
		write(fd, &c, 1);
		(*super_count)++;
		nn /= 10;
	}
}
