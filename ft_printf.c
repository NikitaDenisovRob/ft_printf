/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsato <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:48:26 by jsato             #+#    #+#             */
/*   Updated: 2021/12/20 23:25:33 by jsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_precent(void)
{
	write(1, "%", 1);
	return (1);
}

static int	print_precent_line(va_list pointer, const char *flag)
{
	int	count_of_letters;

	count_of_letters = 0;
	if (*flag == 'c')
		count_of_letters = ft_putchr(va_arg(pointer, int));
	else if (*flag == 's')
		count_of_letters = ft_putstr(va_arg(pointer, char *));
	else if (*flag == '%')
		count_of_letters = ft_print_precent();
	else if (*flag == 'i' || *flag == 'd')
		count_of_letters = ft_print_itoa(va_arg(pointer, long));
	else if (*flag == 'u')
		count_of_letters = ft_print_unsigned_itoa(va_arg(pointer, long));
	else if (*flag == 'p')
		count_of_letters = ft_dec_to_hex(va_arg(pointer, long unsigned int));
	else if (*flag == 'x')
		count_of_letters = ft_print_hex(va_arg(pointer, long unsigned int), 1);
	else if (*flag == 'X')
		count_of_letters = ft_print_hex(va_arg(pointer, long unsigned int), 0);
	return (count_of_letters - 1);
}

int	check_char(const char *n)
{
	if (*n == 'c' || *n == 's')
		return (1);
	else if (*n == '%' || *n == 'i')
		return (1);
	else if (*n == 'd' || *n == 'u')
		return (1);
	else if (*n == 'p' || *n == 'x')
		return (1);
	else if (*n == 'X')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *main_arg, ...)
{
	va_list	ap;
	int		total;

	va_start(ap, main_arg);
	total = 0;
	while (*main_arg)
	{
		if (*main_arg == '%')
		{
			total += print_precent_line(ap, ++main_arg);
		}
		else
			write(1, main_arg, 1);
		main_arg++;
		total += 1;
	}
	va_end(ap);
	return (total);
}
