/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:51:34 by user              #+#    #+#             */
/*   Updated: 2019/08/12 11:59:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(__int128_t num, char *str, unsigned base, unsigned is_upper)
{
	const char	*alphabet = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char		*iter;

	if (num == MIN_INT)
		return (ft_strcpy(str, "-2147483648"));
	iter = str;
	if (base == 10 && num < 0)
	{
		*iter++ = '-';
		num = -num;
	}
	if (!num)
		*iter++ = '0';
	while (num)
	{
		*iter++ = alphabet[num % base];
		num /= base;
	}
	*iter = '\0';
	ft_strrev(str + (*str == '-'));
	return (str);
}