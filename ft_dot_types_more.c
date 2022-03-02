/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_types_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/17 18:05:26 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dot_cx(t_options *ops, void *t, int *super_count)
{
	char		*to_be_free;
	long long	i;

	if (ops->hash && (unsigned int)t > 0)
	{
		ft_putstr_fd("0X", 1);
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
		ft_putstr_fd(to_be_free, 1);
	}
	if (to_be_free)
		free(to_be_free);
}

void	ft_dot_s(t_options *ops, void *t, int *super_count)
{
	int		size;
	char	*s;

	if (t == 0)
		s = "(null)";
	else
		s = (char *)t;
	size = ops->mw;
	while (size && *s)
	{
		write (1, s, 1);
		size--;
		s++;
		(*super_count)++;
	}
}

void	ft_print_dot(t_options *ops, void *t, int *super_count)
{
	if (ops->type == 's')
		ft_dot_s(ops, t, super_count);
	else if (ops->type == 'p')
		ft_dot_p(ops, t, super_count);
	else if (ops->type == 'd' || ops->type == 'u' || ops->type == 'i')
		ft_dot_nums(ops, t, super_count);
	else if (ops->type == 'x')
		ft_dot_x(ops, t, super_count);
	else if (ops->type == 'X')
		ft_dot_cx(ops, t, super_count);
}

int	count_hexes_dot(t_options *ops, void *t)
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

int	ft_count_dot(t_options *ops, void *t)
{
	int		len;

	if (ops->type == 's')
	{
		if (t == 0)
			return (6);
		len = (ft_strlen((char *)t));
	}
	if (ops->type == 'x' || ops->type == 'X' || ops->type == 'p')
		len = (count_hexes_dot(ops, t));
	if (ops->type == 'd' || ops->type == 'i' || ops->type == 'u')
	{
		len = 0;
		ft_count_num((int)t, &len, ops);
		if ((int)t == 0)
			len--;
	}
	return (len);
}
