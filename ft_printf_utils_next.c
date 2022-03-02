/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_next.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/17 17:11:01 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hexes(t_options *ops, void *t)
{
	char	*temp;
	int		len;

	if (ops->type == 'p')
		temp = converter(t, 16, 1);
	else
		temp = converter(t, 16, 0);
	if (temp == 0)
		return (0);
	len = ft_strlen((const char *)temp);
	free (temp);
	if (ops->type == 'p' || (ops->hash && (unsigned int)t > 0))
		len += 2;
	return ((int)len);
}

int	ft_count_len(t_options *ops, void *t)
{
	int		len;

	if (ops->type == 'c' || ops->type == '%')
		return (1);
	if (ops->type == 's')
	{
		if (t == 0)
			return (6);
		return (ft_strlen((char *)t));
	}
	if (ops->type == 'x' || ops->type == 'X' || ops->type == 'p')
		return (count_hexes(ops, t));
	if (ops->type == 'd' || ops->type == 'i' || ops->type == 'u')
	{
		len = 0;
		ft_count_num((int)t, &len, ops);
		if ((int)t < 0 && ops->type != 'u')
			len--;
		return ((int)len);
	}
	return (0);
}

t_options	*create_ops(char c)
{
	t_options	*newops;

	newops = malloc(sizeof(t_options));
	if (newops == 0)
		return (0);
	newops->hash = 0;
	newops->space = 0;
	newops->plus = 0;
	newops->dot = 0;
	newops->minus = 0;
	newops->zero = 0;
	newops->type = c;
	newops->width = 0;
	newops->mw = 0;
	return (newops);
}

void	nully(t_options *ops)
{
	ops->type = 0;
	ops->width = 0;
	ops->plus = 0;
	ops->space = 0;
	ops->hash = 0;
	ops->minus = 0;
	ops->dot = 0;
	ops->zero = 0;
	ops->mw = 0;
}
