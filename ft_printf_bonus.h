/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:42:32 by junylee           #+#    #+#             */
/*   Updated: 2021/08/15 20:10:33 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			n_base;
	int			n_sign;
}				t_info;

void	init_info(t_info *info);
int		is_flag(char c);
int		is_num(char c);
int		is_opt(char c);
int		is_type(char c);
int		ft_len(unsigned long n, unsigned long base);
char	*ft_zero(void);
char	*ft_make(unsigned long num, char *ret, int len, t_info *info);
char	*ft_empty(void);
char	*ft_itoa(unsigned long n, unsigned long base, t_info *info);
void	check_width_prec(va_list ap, t_info *info, char *format, int i);
void	put_info(va_list ap, t_info *info, char *format, int i);
void	print_type(va_list ap, t_info *info, int *ret);
int		ft_parse(va_list ap, char *format);
void	print_width(int width, int len, int zero, int *ret);
void	print_char(int c, t_info *info, int *ret);
void	print_str(char *str, t_info *info, int *ret);
void	print_nbr(long long n, t_info *info, int *ret);
int		ft_printf(const char *foramt, ...);
int		ft_putchar(char c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2, int free_target);
void	put_str(char *str, int len, int *ret);
char	*add_p(char *str);
char	*join_prec(t_info *info, char *str);
char	*join_minus(t_info *info, char *str);
char	*join_width(t_info *info, char *str);
char	*join_minus2(t_info *info, char *str, int len);

#endif
