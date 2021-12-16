/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:05:12 by lcorinna          #+#    #+#             */
/*   Updated: 2021/12/16 17:07:30 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_for_cdiu(char c, va_list argpnt, int size_len)
{
	unsigned int	u;
	long long		j;

	if (c == 'c')
	{
		j = va_arg(argpnt, int);
		return (size_len += ft_putchar_plus_size((char) j));
	}
	else if (c == 'd' || c == 'i')
	{
		j = (long long) va_arg(argpnt, int);
		if (j < 0)
			size_len += 1;
		return (size_len += ft_putnbr_plus_size(j));
	}
	else if (c == 'u')
	{
		u = va_arg(argpnt, unsigned int);
		return (size_len += ft_putnbr_plus_size(u));
	}
	return (size_len);
}

int	ft_for_xX(char c, va_list argpnt, int size_len)
{
	char			*str;
	unsigned int	j;

	j = va_arg(argpnt, unsigned int);
	if (j == 0)
	{
		write(1, "0", 1);
		return (size_len += 1);
	}
	str = number_translation_for_xX(j, c);
	if (str == NULL)
	{
		write(1, "memory was not allocated", 24);
		return (-1);
	}
	ft_putstr(str);
	size_len += ft_strlen(str);
	free(str);
	return (size_len);
}

int	ft_for_p(va_list argpnt, int size_len)
{
	char					*str;
	unsigned long long int	j;

	j = va_arg(argpnt, unsigned long long int);
	if (j == 0)
	{
		write(1, "0x0", 3);
		return (size_len += 3);
	}
	str = number_translation_for_p(j);
	if (str == NULL)
	{
		write(1, "memory was not allocated", 24);
		return (-1);
	}
	write(1, "0x", 2);
	ft_putstr(str);
	size_len += ft_strlen(str) + 2;
	free(str);
	return (size_len);
}

int	ft_distribution(char c, va_list argpnt, int size_len)
{
	char	*str2;

	if (c == 'c' || c == 'd' || c == 'i' || c == 'u')
		return (size_len = ft_for_cdiu(c, argpnt, size_len));
	else if (c == 'p')
		return (size_len = ft_for_p(argpnt, size_len));
	else if (c == 'x' || c == 'X')
		return (size_len = ft_for_xX(c, argpnt, size_len));
	else if (c == 's')
	{
		str2 = va_arg(argpnt, char *);
		if (str2 == NULL)
		{
			write(1, "(null)", 6);
			return (size_len += 6);
		}
		ft_putstr(str2);
		return (size_len += ft_strlen(str2));
	}
	else if (c == '%')
		size_len += ft_putchar_plus_size(c);
	return (size_len);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			size_len;
	va_list		argpnt;

	va_start(argpnt, format);
	i = 0;
	size_len = 0;
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			size_len = ft_distribution(format[i], argpnt, size_len);
			if (size_len < 0)
				return (-1);
		}
		else if ((format[i] > 31 && format[i] < 127) || format[i] == '\n')
			size_len += ft_putchar_plus_size(format[i]);
		i++;
	}
	va_end(argpnt);
	return (size_len);
}
