/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/16 20:43:17 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_shift_bytes(char **str, int size, int bytes)
{
	char	temp;
	int		i;
	int		j;

	i = bytes;
	j = 0;
	while (j < size + 1)
	{
		if (j < ((size + 1) - i))
		{
			temp = (*str)[j];
			(*str)[j] = (*str)[j + i];
			(*str)[j + i] = temp;
		}
		else
			(*str)[j] = '\0';
		j++;
	}
}

void	ft_shift_left(char **str, int size, char c)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	while (i < size && (*str)[i] != '\0')
	{
		if ((*str)[i] == c)
			break ;
		i++;
	}
	i++;
	j = 0;
	while (j < size + 1)
	{
		if (j < ((size + 1) - i))
		{
			temp = (*str)[j];
			(*str)[j] = (*str)[j + i];
			(*str)[j + i] = temp;
		}
		else
			(*str)[j] = '\0';
		j++;
	}
}
