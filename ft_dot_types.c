/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/17 18:33:43 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dot_p(t_options *ops, void *t, int *super_count)
{
	char		*to_be_free;

	(void) ops;
	ft_putstr_fd("0x", 1);
	*super_count += 2;
	if (!(ops->mw == 0 && t == 0))
	{
		to_be_free = converter(t, 16, 1);
		*super_count += (ft_strlen(to_be_free));
		ft_putstr_fd(ft_str_tolower(to_be_free), 1);
		if (to_be_free)
			free(to_be_free);
	}
}

int	ft_dot_bf(t_options *ops, void *t)
{
	if ((ops->plus || ops->space || (int)t < 0) && (ops->zero || ops->minus))
		return (1);
	return (0);
}

int	ft_dot_af(t_options *ops, void *t)
{
	if ((ops->plus || ops->space || (int)t < 0) && !(ops->zero || ops->minus))
		return (1);
	return (0);
}

void	ft_dot_nums(t_options *ops, void *t, int *super_count)
{
	long long	i;

	i = (ft_count_dot(ops, t));
	if ((int)t < 0 && ops->type != 'u')
		i = ops->mw - i + 1;
	else if ((int)t == 0)
		i = ops->mw - i - 1;
	else
		i = ops->mw - i;
	while (i > 0)
	{
		write (1, "0", 1);
		(*super_count)++;
		i--;
	}
	if (!(ops->mw == 0 && t == 0))
		ft_putnbr_dot((int) t, 1, super_count, ops);
}

void	ft_dot_x(t_options *ops, void *t, int *super_count)
{
	char		*to_be_free;
	long long	i;

	if (ops->hash && (unsigned int)t)
	{
		ft_putstr_fd("0x", 1);
		(*super_count) += 2;
	}
	to_be_free = converter(t, 16, 0);
	i = ft_strlen(to_be_free);
	i = ops->mw - i;
	while (i > 0)
	{
		write (1, "0", 1);
		(*super_count)++;
		i--;
	}
	if (!(ops->mw == 0 && t == 0))
	{
		*super_count += ft_strlen(to_be_free);
		ft_putstr_fd(ft_str_tolower(to_be_free), 1);
	}
	if (to_be_free)
		free(to_be_free);
}
