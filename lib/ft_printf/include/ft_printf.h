/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:16:52 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/09 19:28:18 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_convert_format(va_list *args, const char format);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_int(int c);
int		ft_print_unit(unsigned int c);
char	*ft_uitoa(unsigned int c);
int		ft_uni_num_len(unsigned int c);
int		ft_print_hex(unsigned int c, const char format);
int		ft_put_hex(unsigned int num, const char format);
int		ft_print_point(unsigned long long c);
int		ft_point_hex(unsigned long long num);
int		ft_print_percent(void);

#endif