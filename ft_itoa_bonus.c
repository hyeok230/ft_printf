/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:14:13 by junylee           #+#    #+#             */
/*   Updated: 2021/08/15 20:10:48 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_len(unsigned long n, unsigned long base)
{
	int		len;

	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_make(unsigned long num, char *ret, int len, t_info *info)
{
	int				i;
	char			*number;
	unsigned long	base;

	base = info->n_base;
	if (info->type == 'X')
		number = "0123456789ABCDEF";
	else
		number = "0123456789abcdef";
	i = len - 1;
	while (num)
	{
		ret[i] = number[num % base];
		num /= base;
		i--;
	}
	ret[len] = '\0';
	return (ret);
}

char	*ft_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_empty(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_itoa(unsigned long n, unsigned long base, t_info *info)
{
	int		len;
	char	*ret;

	if (n == 0 && info->prec == 0)
		return (ft_empty());
	else if (n == 0)
		return (ft_zero());
	len = ft_len(n, base);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	return (ft_make(n, ret, len, info));
}
