/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsato <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:07:58 by jsato             #+#    #+#             */
/*   Updated: 2021/12/20 19:54:25 by jsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_len_dec(uintptr_t dec)
{
	uintptr_t	m;
	int			len;

	len = 0;
	m = (uintptr_t)dec;
	while (m != 0)
	{
		m = m / 16;
		len++;
	}
	return (len);
}

static void	fin(char *loc, uintptr_t count, int kek)
{
	uintptr_t	delitel;

	while (kek > -1)
	{
		delitel = count / 16;
		if ((count - (delitel * 16)) <= 9)
		{
			loc[kek] = (count - (delitel * 16)) + 48;
		}
		else
		{
			loc[kek] = (count - (delitel * 16)) + 87;
		}
		kek--;
		count = delitel;
	}
}

char	*ft_get_hex(uintptr_t dec)
{
	uintptr_t	hex;
	int			len;
	char		*loc;

	hex = (uintptr_t)dec;
	len = get_len_dec(hex);
	loc = (char *)malloc(len + 1);
	loc[len] = 0;
	fin(loc, hex, len - 1);
	return (loc);
}
