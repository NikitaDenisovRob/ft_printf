/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsato <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:25:57 by jsato             #+#    #+#             */
/*   Updated: 2021/12/19 18:17:41 by jsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_itoa(int n)
{
	char	*loc;
	long	m;
	size_t	len;

	m = n;
	len = ft_get_len(m);
	if (m < 0)
		m *= -1;
	loc = (char *)malloc(len + 1);
	if (loc == (void *)0)
		return ((void *)0);
	loc[len] = 0;
	while (len)
	{
		loc[len - 1] = (m % 10) + '0';
		m /= 10;
		len--;
	}
	if (n < 0)
		*loc = '-';
	return (loc);
}

int	ft_print_itoa(int n)
{
	char	*str;
	int		counter;

	counter = 0;
	str = ft_itoa(n);
	while (str[counter])
	{
		write(1, &str[counter], 1);
		counter++;
	}
	free(str);
	return (counter);
}
