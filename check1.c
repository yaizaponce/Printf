/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yponce-p <yponce-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:28:14 by yponce-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:46:28 by yponce-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_c(va_list elem)
{
	int	c_elem;
	int	ret;

	ret = 0;
	c_elem = va_arg(elem, int);
	ret += write (1, &c_elem, 1);
	return (ret);
}

static int	check_s(va_list elem)
{
	int		i;
	char	*str;
	int		ret;

	i = 0;
	ret = 0;
	str = va_arg(elem, char *);
	if (str == NULL)
		ret += write(1, "(null)", 6);
	else
	{
		while (str[i])
		{
			ret += write(1, &str[i], 1);
			i++;
		}
	}
	return (ret);
}

static int	check_di(va_list elem)
{
	char	*c_elem;
	int		i;
	int		ret;

	c_elem = ft_itoa(va_arg(elem, int));
	i = 0;
	ret = 0;
	while (c_elem[i])
	{
		write(1, &c_elem[i], 1);
		i++;
		ret++;
	}
	free(c_elem);
	return (ret);
}

static int	print_u(va_list elem)
{
	char	*c_elem;
	int		i;
	int		ret;

	c_elem = ft_utoa(va_arg(elem, unsigned int));
	i = 0;
	ret = 0;
	while (c_elem[i])
	{
		write(1, &c_elem[i], 1);
		i++;
		ret++;
	}
	free(c_elem);
	return (ret);
}

int	check1(const char s, va_list elem)
{
	int	ret;

	ret = 0;
	if (s == 'c')
		ret += check_c(elem);
	if (s == 's')
		ret += check_s(elem);
	if (s == 'd' || s == 'i')
		ret += check_di(elem);
	if (s == 'u')
		ret += print_u(elem);
	return (ret);
}
