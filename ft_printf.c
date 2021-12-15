/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:05:12 by lcorinna          #+#    #+#             */
/*   Updated: 2021/12/15 20:13:37 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *r) // libft
{
	size_t	i;

	i = 0;
	while (r[i])
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len) // libft
{
	int		i;
	char	*e;

	e = b;
	i = 0;
	while (i < (int) len)
	{
		e[i] = c;
		i++;
	}
	return (e);
}

int	ft_intlen(long long i) // to display on the screen
{
	int	size;

	size = 0;
	if (i < 0)
	{
		i *= (-1);
		size += 1;
	}
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

void	ft_putstr(char *s) // to display on the screen
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}

int	ft_putchar_plus_size(char c) // to display on the screen
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_plus_size(long long n) // to display on the screen
{
	char		count;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	count = n % 10 + '0';
	if (n / 10 > 0)
	{
		ft_putnbr_plus_size(n / 10);
	}
	write(1, &count, 1);
	n = ft_intlen(n);
	return (n);
}

char	*revers_str(char *str) // to the hexadecimal system
{
	char	*rev_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rev_str = (char *) malloc(sizeof(char) * ft_strlen(str) + 1);
	if (rev_str == NULL)
		return (NULL);
	rev_str = ft_memset(rev_str, '\0', (ft_strlen(str) + 1));
	while (str[i])
		i++;
	i--;
	while (i >= 0)
		rev_str[j++] = str[i--];
	free(str);
	str = NULL;
	return (rev_str);
}

char	*ft_smal_letters(char *str, long long j) // to the hexadecimal system
{
	int			i;
	long long	remains;

	i = 0;
	while (j > 0)
	{
		remains = j % 16;
		if (remains >= 0 && remains <= 9)
			str[i] = (remains + '0');
		else if (remains >= 10 && remains <= 15)
			str[i] = (remains + 'W');
		i++;
		j = j / 16;
	}
	str[i] = '\0';
	str = revers_str(str);
	return (str);
}

char	*ft_large_letters(char *str, long long j) // to the hexadecimal system
{
	int			i;
	long long	remains;

	i = 0;
	while (j > 0)
	{
		remains = j % 16;
		if (remains >= 0 && remains <= 9)
			str[i] = (remains + '0');
		else if (remains >= 10 && remains <= 15)
			str[i] = (remains + '7');
		i++;
		j = j / 16;
	}
	str[i] = '\0';
	str = revers_str(str);
	return (str);
}

// char	*for_p(char *str, unsigned long int j) // to the hexadecimal system
// {
// }

char	*number_translation(long long j, char c) // to the hexadecimal system
{
	char		*str;
	long long	mem;
	int			i;

	mem = j;
	i = 1;
	while (mem > 0)
	{
		mem /= 16;
		i++;
	}
	str = (char *) malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	i = 0;
	if (c == 'x')
		str = ft_smal_letters(str, j);
	else if (c == 'X')
		str = ft_large_letters(str, j);
	// else if (c == 'p')
	// 	str = ft_smal_letters(str, j); here mistake
	return (str);
}

int	ft_for_cdiu(char c, va_list argpnt, int size_len) // main
{
	unsigned int	u;
	long long		j;

	if (c == 'c')
	{
		j = va_arg(argpnt, int);
		return (size_len += ft_putchar_plus_size(j));
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

int	ft_for_xX(char c, va_list argpnt, int size_len) // main
{
	char			*str;
	unsigned int	j;

	j = va_arg(argpnt, unsigned int);
	if (j == 0)
	{
		write(1, "0", 1);
		return (size_len += 1);
	}
	str = number_translation(j, c);
	if (str == NULL)
	{
		write(1, "memory was not allocated", 24);
		return (0);
	}
	ft_putstr(str);
	size_len += ft_strlen(str);
	free(str);
	return (size_len);
}

int	ft_for_p(char c, va_list argpnt, int size_len) // main
{
	char					*str;
	unsigned long int		j;

	j = va_arg(argpnt, unsigned long int);
	// printf("-->%lld<--\n", j); // here mistake
	if (j == 0)
	{
		write(1, "0x0", 3);
		return (size_len += 3);
	}
	str = number_translation((long long) j, c);
	if (str == NULL)
	{
		write(1, "memory was not allocated", 24);
		return (0);
	}
	write(1, "0x", 2);
	ft_putstr(str);
	size_len += ft_strlen(str) + 2;
	free(str);
	return (size_len);
}

int	ft_distribution(char c, va_list argpnt, int size_len) // main
{
	char			*str2;

	if (c == 'c' || c == 'd' || c == 'i' || c == 'u')
		return (size_len = ft_for_cdiu(c, argpnt, size_len));
	else if (c == 'p')
		return (size_len = ft_for_p(c, argpnt, size_len));
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

int	ft_printf(const char *format, ...) // main
{
	int				i;
	int				size_len;
	va_list			argpnt;

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
			if (size_len == 0)
				return (0);
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

#include <stdio.h>

int	main(void)
{
	int		res_printf;
	int		res_ft_printf;
	char 	str[] = "wer";

	res_printf = printf(" %p \n", -9223372036854775806);
	printf("res_printf %d\n\n", res_printf);
	res_ft_printf = ft_printf(" %p \n", -9223372036854775806);
	printf("res_ft_printf %d\n", res_ft_printf);
	return (0);
}

// int	main(void)
// {
// 	char			c;
// 	char			*str;
// 	void			*vd;
// 	int				i;
// 	unsigned int	j;

// 	printf("c - %lu\n", sizeof(c)); // c - 1
// 	printf("str - %lu\n", sizeof(str)); // str - 8
// 	printf("vd - %lu\n", sizeof(vd)); // vd - 8
// 	printf("i - %lu\n", sizeof(i)); // i - 4
// 	printf("j - %lu\n", sizeof(j)); // j - 4
// 	return (0);
// }

//printf("pip");
//%cspdiux%
//%c %s %p %d %i %u %x %X %%

// static long long	ft_number(char *done)
// {
// 	long long	res;
// 	int			i;

// 	i = 0;
// 	res = 0;
// 	while (done[i] > 47 && done[i] < 58)
// 	{
// 		res = res * 10 + (done[i] - 48);
// 		i++;
// 	}
// 	return (res);
// }

// int	ft_atoi(const char *str)
// {
// 	long long	res;
// 	int			i;

// 	res = 0;
// 	i = 0;
// 	while ((str[i] == 32) || (str[i] > 8 && str[i] < 14))
// 		i++;
// 	if (str[i] == 45)
// 		res = (ft_number((char *) &str[++i]) * (-1));
// 	else if (str[i] == 43)
// 		res = (ft_number((char *) &str[++i]));
// 	else
// 		res = (ft_number((char *) &str[i]));
// 	return (res);
// }

// int	sumnum(int *num, ...)
// {
// 	int		sum;
// 	void	*ptr;
// 	int		nnn;
// 	int		i;
// 	//va_list	argptr;

// 	sum = 0;
// 	ptr = num + 108;
// 	i = *num;
// 	//va_start(argptr, num);
// 	while (i > 0)
// 	{
// 		nnn = ft_atoi((char *) ptr);
// 		//nnn = ft_atoi(va_arg(argptr, char*));
// 		sum += nnn;
// 		ptr += 2;
// 		i--;
// 	}
// 	//va_end(argptr);
// 	return (sum);
// }

// int	main(int argc, char **argv)
// {
// 	int		total;
// 	int		tmp;

// 	tmp = argc - 1;
// 	total = sumnum(&tmp, &argv[1], &argv[2]);
// 	//total = sumnum(5, 1, 1, 1, 1, 1);
// 	printf("%d\n", total);
// 	// str = fullstr(str, qqq, www, eee);
// 	// str = fullstr(argv[1]);
// 	// printf("%s", str);
// 	return (0);
// }

// //%cspdiux%
// //%c %s %p %d %i %u %x %X %%