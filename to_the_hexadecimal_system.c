/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_the_hexadecimal_system.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:29:12 by lcorinna          #+#    #+#             */
/*   Updated: 2021/12/16 16:55:32 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_letters_for_p(char *str, unsigned long long int j)
{
	int						i;
	unsigned long long int	remains;

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

char	*ft_smal_letters(char *str, long long int j)
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

char	*ft_large_letters(char *str, long long j)
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

char	*number_translation_for_p(unsigned long long int j)
{
	char					*str;
	unsigned long long int	mem;
	int						i;

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
	str = ft_letters_for_p(str, j);
	return (str);
}

char	*number_translation_for_xX(long long j, char c)
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
	if (c == 'x')
		str = ft_smal_letters(str, j);
	else if (c == 'X')
		str = ft_large_letters(str, j);
	return (str);
}
