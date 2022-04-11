/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yponce-p <yponce-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:59:41 by yponce-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:32:28 by yponce-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char			*nbr;
	int				len;
	unsigned int	copy;
	int				i;

	i = 1;
	copy = n;
	len = n_len(n);
	nbr = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	while (i <= len)
	{
		nbr[len - i] = copy % 10 + '0';
		copy /= 10;
		i++;
	}
	return (nbr);
}
