/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/16 20:43:29 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long long			i;
	int							p;
	long int					res;

	i = 0;
	p = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == 45)
		p = -1;
	if (*str == 45 || *str == 43)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = ((*str) - 48) + (i * 10);
		if (i > 2147483646 && *(str + 1) >= '0' && *(str + 1) <= '9' && p == 1)
			return (-1);
		if (i > 2147483647 && *(str + 1) >= '0' && *(str + 1) <= '9' && p == -1)
			return (0);
		str++;
	}
	res = p * (int) i;
	return (res);
}

int	ft_atoi_ex(const char *str)
{
	unsigned long long			i;
	int							p;
	long int					res;

	i = 0;
	p = 1;
	while (*str == '-' || *str == '.'
		|| *str == '#' || *str == ' ' || *str == '+')
		str++;
	if (*str == 45)
		p = -1;
	if (*str == 45 || *str == 43)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = ((*str) - 48) + (i * 10);
		if (i > 2147483646 && *(str + 1) >= '0' && *(str + 1) <= '9' && p == 1)
			return (-1);
		if (i > 2147483647 && *(str + 1) >= '0' && *(str + 1) <= '9' && p == -1)
			return (0);
		str++;
	}
	res = p * (int) i;
	return (res);
}
