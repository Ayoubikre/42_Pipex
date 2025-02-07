/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:05:03 by aakritah          #+#    #+#             */
/*   Updated: 2024/11/15 16:35:08 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *t, ...);
int		ft_print_c(char c, va_list ptr);
int		ft_print_d(char n, va_list ptr);
int		ft_print_p(va_list ptr);
int		ft_print_s(va_list ptr);
int		ft_print_x(char n, va_list ptr);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(const char *s);
size_t	ft_strlen(const char *s);

#endif