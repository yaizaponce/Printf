/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yponce-p <yponce-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:36:32 by yponce-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:31:07 by yponce-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hexa(unsigned int aux)
{
	int	ret;

	ret = 0;
	if (aux == 0)
		ret = 1;
	else
	{
		while (aux > 0)
		{
			ret++;
			aux /= 16;
		}
	}
	return (ret);
}

static int	print_hexa(unsigned int nbr, char type, char *b_min, char *b_may)
{
	unsigned int	aux;

	aux = nbr;
	if (nbr >= 16)
	{
		print_hexa(nbr / 16, type, b_min, b_may);
		print_hexa(nbr % 16, type, b_min, b_may);
	}
	else
	{
		if (type == 'x')
			write(1, &b_min[nbr], 1);
		if (type == 'X')
			write(1, &b_may[nbr], 1);
	}
	return (len_hexa(aux));
}

int	check3(const char s, va_list elem)
{
	char			type;
	char			*b_min;
	char			*b_may;
	unsigned int	hex_elem;
	int				ret;

	ret = 0;
	b_min = "0123456789abcdef";
	b_may = "0123456789ABCDEF";
	hex_elem = va_arg(elem, unsigned int);
	if (s == 'x')
		type = 'x';
	if (s == 'X')
		type = 'X';
	ret += print_hexa(hex_elem, type, b_min, b_may);
	return (ret);
}
