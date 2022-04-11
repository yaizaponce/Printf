/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yponce-p <yponce-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:35:46 by yponce-p          #+#    #+#             */
/*   Updated: 2022/03/31 20:07:00 by yponce-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_p(unsigned long aux)
{
	int	ret;

	ret = 0;
	while (aux > 0)
	{
		ret++;
		aux /= 16;
	}
	return (ret);
}

static int	print_p(unsigned long nbr, char *base, int aux)
{
	unsigned long	copy;

	copy = nbr;
	if (aux != 0)
		write(1, "0x", 2);
	aux = 0;
	if (nbr >= 16)
	{
		print_p(nbr / 16, base, aux);
		print_p(nbr % 16, base, aux);
	}
	else
		write(1, &base[nbr], 1);
	return (len_p(copy));
}

int	check2(va_list elem)
{
	int				aux;
	char			*base;
	unsigned long	p_elem;
	int				ret;

	ret = 0;
	aux = 1;
	base = "0123456789abcdef";
	p_elem = va_arg(elem, unsigned long);
	if (p_elem == 0)
		ret += write(1, "0x0", 3);
	else
		ret += print_p(p_elem, base, aux) + 2;
	return (ret);
}
