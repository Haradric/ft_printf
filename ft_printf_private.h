/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:04:48 by mbraslav          #+#    #+#             */
/*   Updated: 2017/02/16 16:21:32 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>

typedef struct		s_flag
{
	int				minus;
	int				plus;
	int				space;
	int				hash;
	int				zero;
}					t_flag;

typedef struct		s_arg
{
	intmax_t		integer;
	uintmax_t		uinteger;
	wchar_t			*maxstring;
	wint_t			maxchar;
	char			ch;
	char			*string;
	void			*pointer;
}					t_arg;

typedef struct		s_description
{
	t_arg			param;
	va_list			args;
	t_flag			flag;
	char			*result;
	size_t			len;
	int				width;
	int				precision;
	int				length;
	char			type;


}					t_description;

int					ft_printf(const char *format, ...);
size_t				read_modifiers(char *str, t_description *conversion);
void				clean_description(t_description *conversion);
size_t				read_flags(char *str, t_description *conversion);
size_t				read_width(char *str, t_description *conversion);
size_t				read_precision(char *str, t_description *conversion);
size_t				read_length(char *str, t_description *conversion);
size_t				read_type(char *str, t_description *conversion);
size_t				read_args(t_description *conversion);

int					taking_without_length(t_description *conversion);
int					taking_with_l(t_description *conversion);
int					taking_with_hh(t_description *conversion);
int					taking_with_h(t_description *conversion);
int					taking_with_ll(t_description *conversion);
int					taking_with_j(t_description *conversion);
int					taking_with_z(t_description *conversion);

size_t				process_modifiers(t_description *conversion);
size_t				processing_percent(t_description *conversion);
size_t				processing_x(t_description *conversion);
size_t				processing_s(t_description *conversion);
size_t				processing_ls(t_description *conversion);
size_t				processing_c(t_description *conversion);
size_t				processing_o(t_description *conversion);
size_t				processing_di(t_description *conversion);
size_t				processing_u(t_description *conversion);
size_t				processing_p(t_description *conversion);
size_t				processing_0(t_description *conversion);

void				expand_str(char **s1, const char *s2, int pos);
char				*itoa_base(intmax_t n, int base);
char				*uitoa_base(uintmax_t n, int base);
void				strtoupper(char *str);
int					power(int x, size_t n);

size_t				wchar_len(wint_t wchar);
char				*wchar_to_char(wchar_t wchar);

#endif

