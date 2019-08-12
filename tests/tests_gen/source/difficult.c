/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 09:51:38 by sleonia           #+#    #+#             */
/*   Updated: 2019/06/29 09:51:41 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_check.h"

void			hard_square_10(char ***figures, int fd)
{
	int			i;

	i = 0;
	while (i < 10)
	{
		(*figures)[0] = F_1;
		ft_putstr_fd((*figures)[0], fd);
		if ((i + 1) != 10)
			write(fd, "\n", 1);
		i++;
	}
}

void			hard_pipe_26(char ***figures, int fd)
{
	int			i;

	i = 0;
	while (i < 26)
	{
		(*figures)[0] = F_3;
		ft_putstr_fd((*figures)[0], fd);
		if ((i + 1) != 26)
			write(fd, "\n", 1);
		i++;
	}
}

void			hard_random_15_v1(char ***figures, int fd)
{
	int			i;

	i = 0;
	(*figures)[0] = F_13;
	(*figures)[1] = F_9;
	(*figures)[2] = F_1;
	(*figures)[3] = F_15;
	(*figures)[4] = F_17;
	(*figures)[5] = F_10;
	(*figures)[6] = F_1;
	(*figures)[7] = F_10;
	(*figures)[8] = F_12;
	(*figures)[9] = F_16;
	(*figures)[10] = F_11;
	(*figures)[11] = F_17;
	(*figures)[12] = F_14;
	(*figures)[13] = F_8;
	(*figures)[14] = F_16;
	while (i < 15)
	{
		ft_putstr_fd((*figures)[i], fd);
		if ((i + 1) != 15)
			write(fd, "\n", 1);
		i++;
	}
}

void			hard_random_12(char ***figures, int fd)
{
	int			i;

	i = 0;
	(*figures)[0] = F_1;
	(*figures)[1] = F_3;
	(*figures)[2] = F_6;
	(*figures)[3] = F_10;
	(*figures)[4] = F_1;
	(*figures)[5] = F_13;
	(*figures)[6] = F_3;
	(*figures)[7] = F_19;
	(*figures)[8] = F_1;
	(*figures)[9] = F_14;
	(*figures)[10] = F_15;
	(*figures)[11] = F_13;
	while (i < 12)
	{
		ft_putstr_fd((*figures)[i], fd);
		if ((i + 1) != 12)
			write(fd, "\n", 1);
		i++;
	}
}

void			hard_random_15_v2(char ***figures, int fd)
{
	int			i;

	i = 0;
	(*figures)[0] = F_4;
	(*figures)[1] = F_7;
	(*figures)[2] = F_12;
	(*figures)[3] = F_1;
	(*figures)[4] = F_13;
	(*figures)[5] = F_1;
	(*figures)[6] = F_18;
	(*figures)[7] = F_4;
	(*figures)[8] = F_1;
	(*figures)[9] = F_1;
	(*figures)[10] = F_13;
	(*figures)[11] = F_17;
	(*figures)[12] = F_17;
	(*figures)[13] = F_2;
	(*figures)[14] = F_13;
	while (i < 15)
	{
		ft_putstr_fd((*figures)[i], fd);
		if ((i + 1) != 15)
			write(fd, "\n", 1);
		i++;
	}
}