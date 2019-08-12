/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:27:05 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/12 13:57:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*str1;
	char	*str2;

	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	else
	{
		str1 = (char *)s1;
		str2 = (char *)s2;
		if (str1 && str2)
		{
			if (ft_strncmp(str1, str2, n) == 0)
				return (1);
		}
	}
	return (0);
}
