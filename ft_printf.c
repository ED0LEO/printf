/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/16 20:43:17 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char *s, int *super_count)
{
	while (*s != '%' && *s)
	{
		write(1, s, 1);
		(*super_count)++;
		s++;
	}
}

void	read_cycle(char **str, int *super_count, t_options *ops, va_list *ap)
{
	void	*t;

	while (1)
	{
		ft_print(*str, super_count);
		ft_shift_left(str, ft_strlen(*str), '%');
		if (find_type(*str, ops))
		{
			if (ops->type != '%')
				t = va_arg(*ap, void *);
			ft_pr(ops, t, super_count);
			ft_shift_bytes(str, ft_strlen(*str), count_flags(*str));
		}
		else
		{
			if (ft_strlen(*str) > 1)
				ft_print(*str, super_count);
			break ;
		}
	}
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	t_options	*ops;
	int			super_count;
	char		*str;

	ops = create_ops(0);
	if (ops == 0)
		return (0);
	va_start(ap, s);
	str = ft_strdup(s);
	if (str == 0)
	{
		free (ops);
		return (0);
	}
	super_count = 0;
	read_cycle(&str, &super_count, ops, &ap);
	va_end(ap);
	free (ops);
	if (str != 0)
		free (str);
	return (super_count);
}
