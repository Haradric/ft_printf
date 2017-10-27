/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:15:44 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/08 13:15:46 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*take_description(const char *str)
{
	char	*s;
	size_t	len;

	len = 0;
	s = (char *)str;
	while (*s != '\0' && ft_strchr("%-+ #0123456789.lhjztlsSpdDioOuUxXcC", *s))
	{
		s++;
		len++;
	}
	return (ft_strsub(str, 0, len));
}

size_t	read_modifiers(char *str, t_description *conversion)
{
	size_t	len;
	size_t	diff;

	len = 1;
	diff = len;
	while (diff != 0)
	{
		diff = len;
		len += read_flags(str + len, conversion);
		len += read_width(str + len, conversion);
		len += read_precision(str + len, conversion);
		len += read_length(str + len, conversion);
		diff = len - diff;
	}
	len += read_type(str + len, conversion);
	if (conversion->type != '%' && conversion->type != '0' &&
		conversion->type != '\0')
		read_args(conversion);
	return (len);
}
