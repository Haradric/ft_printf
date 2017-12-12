/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:04:38 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/01 18:04:42 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t	print_format(t_description *conversion)
{
	if (conversion->result == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		write(1, conversion->result, conversion->len);
		return (conversion->len);
	}
}

int		ft_printf(const char *format, ...)
{
	char			*str;
	t_description	conversion;
	size_t			len;

	len = 0;
	str = (char *)format;
	va_start(conversion.args, format);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			clean_description(&conversion);
			str += read_modifiers(str, &conversion);
			process_modifiers(&conversion);
			len += print_format(&conversion);
			free(conversion.result);
			continue ;
		}
		write(1, str++, 1);
		len++;
	}
	va_end(conversion.args);
	return ((int)len);
}
