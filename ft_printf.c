/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yponce-p <yponce-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:39:54 by yponce-p          #+#    #+#             */
/*   Updated: 2022/03/31 18:16:47 by yponce-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(const char s, va_list elem)
{
	int	ret;

	ret = 0;
	if (s == 'c' || s == 's' || s == 'd' || s == 'i' || s == 'u')
		ret += check1(s, elem);
	if (s == 'p')
		ret += check2(elem);
	if (s == 'x' || s == 'X')
		ret += check3(s, elem);
	if (s == '%')
		ret += write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	elem;
	int		total;
	int		i;

	va_start(elem, s);
	total = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			total += check(s[i], elem);
		}
		else
		{
			write(1, &s[i], 1);
			total++;
		}
		i++;
	}
	va_end(elem);
	return (total);
}
