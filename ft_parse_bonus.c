/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <junylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:01:59 by junylee           #+#    #+#             */
/*   Updated: 2021/08/15 20:11:23 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	check_width_prec(va_list ap, t_info *info, char *format, int i)
{
	if (is_num(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + (format[i] - '0');
		else
			info->prec = info->prec * 10 + (format[i] - '0');
	}
	else if (format[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

void	put_info(va_list ap, t_info *info, char *format, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')
		info->prec = 0;
	else if (is_num(format[i]) || format[i] == '*')
		check_width_prec(ap, info, format, i);
}

void	print_type(va_list ap, t_info *info, int *ret)
{
	char	type;

	type = info->type;
	if (type == 'c')
		print_char(va_arg(ap, int), info, ret);
	else if (type == 's')
		print_str(va_arg(ap, char *), info, ret);
	else if (type == 'p')
		print_nbr(va_arg(ap, long long), info, ret);
	else if (type == 'd' || type == 'i')
		print_nbr(va_arg(ap, int), info, ret);
	else if (type == 'u' || type == 'x' || type == 'X')
		print_nbr(va_arg(ap, unsigned int), info, ret);
	else
		print_char(type, info, ret);
}

int	ft_parse(va_list ap, char *format)
{
	int		ret;
	int		i;
	t_info	info;

	i = 0;
	ret = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			ret += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			i++;
			init_info(&info);
			while (format[i] && is_opt(format[i]) && !is_type(format[i]))
				put_info(ap, &info, format, i++);
			if (!format[i])
				break ;
			info.type = format[i++];
			print_type(ap, &info, &ret);
		}
	}
	return (ret);
}
