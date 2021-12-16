/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:42:31 by lcorinna          #+#    #+#             */
/*   Updated: 2021/12/16 16:54:12 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_intlen_for_printf(long long i);
void	ft_putstr(char *s);
int		ft_putchar_plus_size(char c);
int		ft_putnbr_plus_size(long long n);
char	*revers_str(char *str);
char	*ft_smal_letters(char *str, long long j);
char	*ft_large_letters(char *str, long long j);
char	*ft_letters_for_p(char *str, unsigned long long int j);
char	*number_translation_for_xX(long long j, char c);
char	*number_translation_for_p(unsigned long long int j);
int		ft_for_cdiu(char c, va_list argpnt, int size_len);
int		ft_for_xX(char c, va_list argpnt, int size_len);
int		ft_for_p(va_list argpnt, int size_len);
int		ft_distribution(char c, va_list argpnt, int size_len);
int		ft_printf(const char *format, ...);

#endif