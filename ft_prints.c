/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/17 17:11:41 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pr_bf(t_options *ops, void *t)
{
	if ((ops->plus || ops->space || (int)t < 0) && (ops->zero || ops->minus))
		return (1);
	return (0);
}

int	ft_pr_af(t_options *ops, void *t)
{
	if ((ops->plus || ops->space || (int)t < 0) && !(ops->zero || ops->minus))
		return (1);
	return (0);
}

void	ft_pr(t_options *ops, void *t, int *super_count)
{
	int	i;

	if (ops->dot)
	{
		ft_dot(ops, t, super_count);
		return ;
	}
	i = ops->width - ft_count_len(ops, t);
	if (ft_pr_af(ops, t) && (ops->type == 'd' || ops->type == 'i'))
		i--;
	if (ft_pr_bf(ops, t) && (ops->type == 'd' || ops->type == 'i'))
	{
		i--;
		cons_flags(super_count, ops, t);
	}
	if ((!ops->zero && ops->minus))
		ft_print_type(ops, t, super_count);
	while (i > 0)
		print_fills(ops, super_count, &i);
	if (ft_pr_af(ops, t) && (ops->type == 'd' || ops->type == 'i'))
		cons_flags(super_count, ops, t);
	if (!ops->minus)
		ft_print_type(ops, t, super_count);
}

void	ft_print_type(t_options *ops, void *t, int *super_count)
{
	if (ops->type == 'c')
	{
		(*super_count)++;
		write(1, &t, 1);
	}
	else if (ops->type == '%')
	{
		write (1, "%", 1);
		(*super_count)++;
	}
	else if (ops->type == 's')
		ft_print_string(ops, t, super_count);
	else if (ops->type == 'p')
		ft_print_pointer(ops, t, super_count);
	else if (ops->type == 'd' || ops->type == 'u' || ops->type == 'i')
		ft_print_nums(ops, t, super_count);
	else if (ops->type == 'x')
		ft_print_lowhex(ops, t, super_count);
	else if (ops->type == 'X')
		ft_print_caphex(ops, t, super_count);
}

int	count_flags(char *s)
{
	int	c;

	c = 0;
	while (*s && (ft_isdigit(*s) || *s == '-' || *s == '.'
			|| *s == '#' || *s == ' ' || *s == '+'))
	{
		s++;
		c++;
	}
	c++;
	return (c);
}
