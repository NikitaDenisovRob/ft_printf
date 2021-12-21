/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsato <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:27:32 by jsato             #+#    #+#             */
/*   Updated: 2021/12/20 19:56:57 by jsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_get_hex(uintptr_t dec);
int		ft_dec_to_hex(uintptr_t dec);
int		ft_print_hex(unsigned int count, int format);
int		ft_putchr(int c);
int		ft_putstr(char *str);
size_t	ft_get_len(long n);
int		ft_print_itoa(int n);
int		ft_print_unsigned_itoa(unsigned int n);
int		ft_printf(const char *main_arg, ...);

#endif
