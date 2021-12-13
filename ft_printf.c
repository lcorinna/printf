/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:05:12 by lcorinna          #+#    #+#             */
/*   Updated: 2021/12/13 19:52:40 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(const char *r)
{
	size_t	i;

	i = 0;
	while (r[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(long long n, int fd)
{
	char		count;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	count = n % 10 + '0';
	if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	write(fd, &count, 1);
}

int	ft_intlen(long long i)
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

void	*ft_memset(void *b, int c, size_t len)
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

char	*revers_str(char *str)
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

char	*number_translation(long long j)
{
	char		*str;
	long long	mem;
	int			i;
	char		c;
	int			remains;

	mem = j;
	i = 0;
	while (mem > 0)
	{
		mem /= 16;
		i++;
	}
	i++;
	str = (char *) malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (j > 0)
	{
		mem = j % 16;
		if (mem >= 0 && mem <= 9)
		{
			c = mem + '0';
			str[i] = c;
			i++;
		}
		else if (mem >= 10 && mem <= 15)
		{
			c = mem + 'W';
			str[i] = c;
			i++;
		}
		j = j / 16;
		remains = j;
	}
	str[i] = '\0';
	str = revers_str(str);
	return (str);
}

char	*number_translation_X(long long j)
{
	char		*str;
	long long	mem;
	int			i;
	char		c;
	int			remains;

	mem = j;
	i = 0;
	while (mem > 0)
	{
		mem /= 16;
		i++;
	}
	i++;
	str = (char *) malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (j > 0)
	{
		mem = j % 16;
		if (mem >= 0 && mem <= 9)
		{
			c = mem + '0';
			str[i] = c;
			i++;
		}
		else if (mem >= 10 && mem <= 15)
		{
			c = mem + '7';
			str[i] = c;
			i++;
		}
		j = j / 16;
		remains = j;
	}
	str[i] = '\0';
	str = revers_str(str);
	return (str);
}

int	ft_printf(const char *format, ...)
{
	char			*str;
	int				i;
	long long		j;
	unsigned int	u;
	int				size_len;
	char			*str2;
	char			c;
	va_list			argpnt;

	str = (char *) format;
	va_start(argpnt, format);
	i = 0;
	size_len = 0;
	if (format == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c') // done
			{
				c = (char) va_arg(argpnt, int);
				ft_putchar_fd(c, 1);
				size_len += 1;
			}
			else if (str[i] == 's') // done
			{
				str2 = va_arg(argpnt, char *);
				ft_putstr_fd(str2, 1);
				size_len += ft_strlen(str2);
			}
			else if (str[i] == 'd') // done
			{
				j = (long long) va_arg(argpnt, int);
				ft_putnbr_fd(j, 1);
				size_len += ft_intlen(j);
			}
			else if (str[i] == 'i') // done
			{
				j = (long long) va_arg(argpnt, int);
				ft_putnbr_fd(j, 1);
				size_len += ft_intlen(j);
			}
			else if (str[i] == 'u') // done
			{
				u = va_arg(argpnt, unsigned int);
				ft_putnbr_fd(u, 1);
				size_len += ft_intlen(u);
			}
			else if (str[i] == 'p') // done
			{
				j = va_arg(argpnt, long long);
				str2 = number_translation(j);
				if (str2 == NULL)
				{
					write(1, "memory was not allocated", 24);
					return (-1);
				}
				write(1, "0x", 2);
				ft_putstr_fd(str2, 1);
				size_len += ft_strlen(str2) + 2;
			}
			else if (str[i] == 'x') // done
			{
				j = (long long) va_arg(argpnt, int);
				str2 = number_translation(j);
				ft_putstr_fd(str2, 1);
				size_len += ft_strlen(str2);
			}
			else if (str[i] == 'X') // done
			{
				j = (long long) va_arg(argpnt, int);
				str2 = number_translation_X(j);
				ft_putstr_fd(str2, 1);
				size_len += ft_strlen(str2);
			}
			else if (str[i] == '%') // done
			{
				write(1, &str[i], 1);
				size_len += 1;
			}
		}
		else if (str[i] == '\n')
		{
			write(1, "\n", 1);
			size_len += 1;
		}
		else if (str[i] > 31 && str[i] < 127)
		{
			write(1, &str[i], 1);
			size_len += 1;
		}
		i++;
	}
	va_end(argpnt);
	return (size_len);
}

int	main(void)
{
	int		res_printf;
	int		res_ft_printf;
	char	*str;
	int		i;

	i = 5;
	str = "ti";
	res_printf = printf("%s %d%c%i%c%u%X %x%% %p \n", str, 3, '.', 14, 'd', 0, 15, 256, &i);
	printf("res_printf %d\n\n", res_printf);
	res_ft_printf = ft_printf("%s %d%c%i%c%u%X %x%% %p \n", str, 3, '.', 14, 'd', 0, 15, 256, &i);
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