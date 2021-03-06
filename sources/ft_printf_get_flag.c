/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:11:03 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/23 12:09:50 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_get_flag(const char *input, va_list args, t_flag *flag)
{
	size_t	i;

	i = 0;
	i += ft_printf_get_first_flags(&input[i], flag, args);
	i += ft_printf_get_width(&input[i], args, flag);
	i += ft_printf_get_prec(&input[i], args, flag);
	i += ft_printf_get_add_flags(&input[i], flag);
	i += ft_printf_get_type(&input[i], flag);
	if ((flag->width < 0) && (flag->width != -1))
	{
		flag->minus = 0;
		flag->width *= -1;
	}
	else if (flag->width == -1)
		flag->minus = 0;
	return (i);
}
