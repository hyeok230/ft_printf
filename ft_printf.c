/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:28:10 by junylee           #+#    #+#             */
/*   Updated: 2021/08/15 19:42:11 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(int width, int len, int zero, int *ret)
{
	while (width > len)
	{
		if (zero == 1)
			*ret += ft_putchar('0');
		else
			*ret += ft_putchar(' ');
		len++;
	}
}

void	print_char(int c, t_info *info, int *ret)
{
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		*ret += ft_putchar(c);
	print_width(info->width, 1, info->zero, ret);
	if (info->minus == 0)
		*ret += ft_putchar(c);
}

void	print_str(char *str, t_info *info, int *ret)
{
	int		len;
	char	*null;

	null = "(null)";
	if (!str)
		str = null;
	len = ft_strlen(str);
	if (info->zero == 1 && info->minus == 1)
		info->zero = 0;
	if (info->prec >= 0 && len > info->prec)
		len = info->prec;
	if (info->minus == 1)
		put_str(str, len, ret);
	print_width(info->width, len, info->zero, ret);
	if (info->minus == 0)
		put_str(str, len, ret);
}

void	print_nbr(long long n, t_info *info, int *ret)
{
	char	type;
	int		len;
	char	*str;

	type = info->type;
	if (info->zero == 1 && (info->prec >= 0 || info->minus == 1))
		info->zero = 0;
	if (type == 'p' || type == 'x' || type == 'X')
		info->n_base = 16;
	if ((type == 'd' || type == 'i') && n < 0)
	{
		info->n_sign = -1;
		n = -n;
	}
	str = ft_itoa(n, info->n_base, info);
	str = join_prec(info, str);
	str = join_minus(info, str);
	len = ft_strlen(str);
	if (info->type == 'p')
		str = add_p(str);
	str = join_width(info, str);
	str = join_minus2(info, str, len);
	put_str(str, ft_strlen(str), ret);
	free(str);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_parse(ap, (char *)format);
	va_end(ap);
	return (ret);
}
