/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_from_dec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsato <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:15:48 by jsato             #+#    #+#             */
/*   Updated: 2021/12/19 18:15:15 by jsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_dec_to_hex(uintptr_t dec)
{
	char	*str;
	int		total;

	write(1, "0x", 2);
	if (!dec)
	{
		write(1, "0", 1);
		return (3);
	}
	str = ft_get_hex(dec);
	total = ft_putstr(str);
	free(str);
	return (total + 2);
}
