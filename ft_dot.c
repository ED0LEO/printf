/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/17 18:13:11 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_fills(t_options *ops, int *super_count, int *i)
{
	(*super_count)++;
	if ((ops->zero && !ops->minus))
		write(1, "0", 1);
	else
		write(1, " ", 1);
	(*i)--;
}

void	flags_n_prints(t_options *ops, void *t, int *super_count, int *i)
{
	if (ft_dot_bf(ops, t) && (ops->type == 'd' || ops->type == 'i'))
	{
		(*i)--;
		cons_flags(super_count, ops, t);
	}
	if ((!ops->zero && ops->minus))
		ft_print_dot(ops, t, super_count);
	while (*i > 0 && ops->type != 's')
		print_fills(ops, super_count, i);
	if (ft_dot_af(ops, t) && (ops->type == 'd' || ops->type == 'i'))
		cons_flags(super_count, ops, t);
	if (!ops->minus)
		ft_print_dot(ops, t, super_count);
}

void	ft_dot(t_options *ops, void *t, int *super_count)
{
	int	i;

	if (ops->type == 'c' || ops->type == '%')
	{
		ft_print_type(ops, t, super_count);
		return ;
	}
	ops->zero = 0;
	i = (ft_count_dot(ops, t));
	if (i < ops->mw)
		i = ops->mw;
	i = ops->width - i;
	if ((int)t < 0)
		i--;
	if (ft_dot_af(ops, t) && (ops->type == 'd' || ops->type == 'i'))
		i--;
	flags_n_prints(ops, t, super_count, &i);
}
