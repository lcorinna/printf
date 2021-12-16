/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_display_on_the_screen.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:14:47 by lcorinna          #+#    #+#             */
/*   Updated: 2021/12/16 16:55:10 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen_for_printf(long long i)
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

void	ft_putstr(char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}

int	ft_putchar_plus_size(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_plus_size(long long n)
{
	char	count;

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
	n = ft_intlen_for_printf(n);
	return (n);
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
