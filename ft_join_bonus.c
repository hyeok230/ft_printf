/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <junylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:48:25 by junylee           #+#    #+#             */
/*   Updated: 2021/08/15 20:09:49 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*add_p(char *str)
{
	str = ft_strjoin("0x", str, 2);
	return (str);
}

char	*join_prec(t_info *info, char *str)
{
	int		len;
	int		i;
	char	*plus;

	len = ft_strlen(str);
	i = 0;
	if (info->prec > len)
	{
		len = info->prec - len;
		plus = (char *)malloc(sizeof(char) * (len + 1));
		if (!plus)
			return (NULL);
		while (i < len)
		{
			plus[i++] = '0';
		}
		plus[len] = '\0';
		str = ft_strjoin(plus, str, 3);
	}
	return (str);
}

char	*join_minus(t_info *info, char *str)
{
	if ((info->type == 'i' || info->type == 'd') && info->n_sign == -1
		&& info->zero == 0)
	{
		str = ft_strjoin("-", str, 2);
	}
	return (str);
}

char	*join_width(t_info *info, char *str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = str;
	if (info->width > (int)ft_strlen(str))
	{
		ret = (char *)malloc(sizeof(char) * (info->width - ft_strlen(str) + 1));
		while (i < info->width - ft_strlen(str))
		{
			if (info->zero == 1)
				ret[i] = '0';
			else
				ret[i] = ' ';
			i++;
		}
		ret[i] = '\0';
		if (info->minus == 0)
			ret = ft_strjoin(ret, str, 3);
		else
			ret = ft_strjoin(str, ret, 3);
	}
	return (ret);
}

char	*join_minus2(t_info *info, char *str, int len)
{
	if (info->n_sign == -1 && info->zero == 1)
	{
		if (info->width <= len)
		{
			str = ft_strjoin("-", str, 2);
		}
		else
		{
			str[0] = '-';
		}
	}
	return (str);
}
