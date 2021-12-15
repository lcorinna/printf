/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_display_on_the_screen.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:14:47 by lcorinna          #+#    #+#             */
/*   Updated: 2021/12/15 18:34:28 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_intlen(long long i)
// {
// 	int	size;

// 	size = 0;
// 	if (i < 0)
// 	{
// 		i *= (-1);
// 		size += 1;
// 	}
// 	if (i == 0)
// 		return (1);
// 	while (i > 0)
// 	{
// 		i /= 10;
// 		size++;
// 	}
// 	return (size);
// }

// void	ft_putstr(char *s)
// {
// 	while (*s != '\0')
// 	{
// 		write(1, s, 1);
// 		s++;
// 	}
// }

// int	ft_putchar_plus_size(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// int	ft_putnbr_plus_size(long long n)
// {
// 	char		count;

// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		n *= -1;
// 	}
// 	count = n % 10 + '0';
// 	if (n / 10 > 0)
// 	{
// 		ft_putnbr_plus_size(n / 10);
// 	}
// 	write(1, &count, 1);
// 	n = ft_intlen(n);
// 	return (n);
// }
