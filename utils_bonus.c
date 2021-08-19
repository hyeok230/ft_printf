/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:14:53 by junylee           #+#    #+#             */
/*   Updated: 2021/08/15 20:12:02 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
	info->n_base = 10;
	info->n_sign = 1;
}

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '.' || c == '*');
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_opt(char c)
{
	return (is_flag(c) || is_num(c));
}

int	is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		   || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}
