/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:03:35 by ymanilow          #+#    #+#             */
/*   Updated: 2019/08/12 13:43:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_point_move(t_shape *shape)
{
	size_t	i;
	size_t	j;

	j = 0 - 1;
	i = shape->points[0].x;
	while (++j < 4)
		shape->points[j].x -= i;
	j = shape->points[0].y;
	if (j > shape->points[1].y)
		j = shape->points[1].y;
	if (j > shape->points[2].y)
		j = shape->points[2].y;
	i = 0 - 1;
	while (++i < 4)
		shape->points[i].y -= j;
	return ;
}

int				ft_point_struct(char *s, t_shape *shape)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			shape->points[j].x = i / 5;
			shape->points[j].y = i % 5;
			j++;
		}
		i++;
	}
	return (1);
}

int				ft_check_shapes(char *s)
{
	size_t	i;
	size_t	shapes;

	i = 0 - 1;
	shapes = 0;
	while (++i < 20)
		if (s[i] == '#')
		{
			shapes += i > 4 && s[i - 5] == '#';
			shapes += i % 5 && s[i - 1] == '#';
			shapes += i < 14 && s[i + 5] == '#';
			shapes += s[i + 1] == '#';
		}
	if (shapes < 6)
		return (0);
	return (1);
}

int				ft_check_symbols(char *s, size_t rd)
{
	size_t	i;
	size_t	new_lines;
	size_t	sharps;

	i = 0 - 1;
	sharps = 0;
	new_lines = 0;
	while (++i < 20)
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		if (!((i + 1) % 5) && s[i] != '\n')
			return (0);
		if (s[i] == '#')
			sharps++;
		else if (s[i] == '\n')
			new_lines++;
	}
	if (sharps != 4 || new_lines != 4 || (rd == 21 && s[20] != '\n'))
		return (0);
	return (1);
}

size_t			ft_input(int fd, t_shape **shapes)
{
	size_t		rd;
	size_t		check;
	t_shape		shape;
	size_t		count;
	char		s[21];

	count = 0;
	while ((rd = read(fd, s, 21)))
	{
		++count;
		if (rd != 20 && rd != 21)
			return (0);
		if (!ft_check_symbols(s, rd))
			return (0);
		if (!ft_check_shapes(s))
			return (0);
		ft_point_struct(s, &shape);
		ft_point_move(&shape);
		ft_list_add_to_end(shapes, ft_list_new(&shape));
		check = rd;
	}
	if (check != 20)
		return (0);
	return (count);
}
