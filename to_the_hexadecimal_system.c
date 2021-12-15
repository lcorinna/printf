/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_the_hexadecimal_system.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:29:12 by lcorinna          #+#    #+#             */
/*   Updated: 2021/12/15 18:34:23 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char	*revers_str(char *str)
// {
// 	char	*rev_str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	rev_str = (char *) malloc(sizeof(char) * ft_strlen(str) + 1);
// 	if (rev_str == NULL)
// 		return (NULL);
// 	rev_str = ft_memset(rev_str, '\0', (ft_strlen(str) + 1));
// 	while (str[i])
// 		i++;
// 	i--;
// 	while (i >= 0)
// 		rev_str[j++] = str[i--];
// 	free(str);
// 	str = NULL;
// 	return (rev_str);
// }

// char	*ft_smal_letters(char *str, long long j)
// {
// 	int			i;
// 	long long	remains;

// 	i = 0;
// 	while (j > 0)
// 	{
// 		remains = j % 16;
// 		if (remains >= 0 && remains <= 9)
// 			str[i] = (remains + '0');
// 		else if (remains >= 10 && remains <= 15)
// 			str[i] = (remains + 'W');
// 		i++;
// 		j = j / 16;
// 	}
// 	str[i] = '\0';
// 	str = revers_str(str);
// 	return (str);
// }

// char	*ft_large_letters(char *str, long long j)
// {
// 	int			i;
// 	long long	remains;

// 	i = 0;
// 	while (j > 0)
// 	{
// 		remains = j % 16;
// 		if (remains >= 0 && remains <= 9)
// 			str[i] = (remains + '0');
// 		else if (remains >= 10 && remains <= 15)
// 			str[i] = (remains + '7');
// 		i++;
// 		j = j / 16;
// 	}
// 	str[i] = '\0';
// 	str = revers_str(str);
// 	return (str);
// }

// char	*number_translation(long long j, char c)
// {
// 	char		*str;
// 	long long	mem;
// 	int			i;

// 	mem = j;
// 	i = 1;
// 	while (mem > 0)
// 	{
// 		mem /= 16;
// 		i++;
// 	}
// 	str = (char *) malloc(sizeof(char) * i);
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	if (c == 'x' || c == 'p')
// 		str = ft_smal_letters(str, j);
// 	else
// 		str = ft_large_letters(str, j);
// 	return (str);
// }
