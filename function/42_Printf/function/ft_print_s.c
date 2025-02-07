/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:52:52 by aakritah          #+#    #+#             */
/*   Updated: 2024/11/13 12:33:07 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_s(va_list ptr)
{
	const char	*t = va_arg(ptr, char *);

	if (t == NULL)
		t = "(null)";
	ft_putstr(t);
	return (ft_strlen(t));
}
