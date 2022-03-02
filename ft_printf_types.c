/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/16 20:43:17 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(t_options *ops, void *t, int *super_count)
{
	int	size;

	(void) ops;
	if (t == 0)
	{
		write (1, "(null)", 6);
		*super_count += 6;
		return ;
	}
	size = (ft_strlen((const char *) t));
	ft_putstr_fd(t, 1);
	*super_count += size;
}

void	ft_print_pointer(t_options *ops, void *t, int *super_count)
{
	char		*to_be_free;

	(void) ops;
	ft_putstr_fd("0x", 1);
	to_be_free = converter(t, 16, 1);
	*super_count += (ft_strlen(to_be_free) + 2);
	ft_putstr_fd(ft_str_tolower(to_be_free), 1);
	if (to_be_free)
		free(to_be_free);
}

void	ft_print_nums(t_options *ops, void *t, int *super_count)
{
	ft_putnbr_fd((int) t, 1, super_count, ops);
}

void	ft_print_lowhex(t_options *ops, void *t, int *super_count)
{
	char		*to_be_free;

	if (ops->hash && (unsigned int)t)
	{
		ft_putstr_fd("0x", 1);
		(*super_count) += 2;
	}
	to_be_free = converter(t, 16, 0);
	*super_count += ft_strlen(to_be_free);
	ft_putstr_fd(ft_str_tolower(to_be_free), 1);
	if (to_be_free)
		free(to_be_free);
}

void	ft_print_caphex(t_options *ops, void *t, int *super_count)
{
	char		*to_be_free;

	if (ops->hash && (unsigned int)t > 0)
	{
		ft_putstr_fd("0X", 1);
		(*super_count) += 2;
	}
	to_be_free = converter(t, 16, 0);
	*super_count += ft_strlen(to_be_free);
	ft_putstr_fd(to_be_free, 1);
	if (to_be_free)
		free(to_be_free);
}
