/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yponce-p <yponce-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:34:16 by yponce-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:04:23 by yponce-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include <stdarg.h>

int		check3(const char s, va_list elem);
int		check2(va_list elem);
int		check1(const char s, va_list elem);
int		ft_printf(const char *s, ...);
char	*ft_utoa(unsigned int n);

#endif
