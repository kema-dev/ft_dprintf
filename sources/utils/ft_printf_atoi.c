/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:14:53 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/22 12:35:41 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_atoi(const char *nptr)
{
	unsigned int	n;
	int				neg;

	neg = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	if (*nptr < '0' || *nptr > '9')
		return (0);
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + *nptr - '0';
		nptr++;
	}
	n *= neg;
	return (n);
}
