/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:11:25 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/14 15:11:28 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "solve.h"
#include "shape.h"

typedef struct	s_map
{
	char **map;
	size_t map_size;
}				t_map;


void fill_map(char ***map, size_t mapsize)
{
	size_t row;
	size_t col;

	row = 0;
	while (row < mapsize)
	{
		col = 0;
		while (col < mapsize)
			(*map)[row][col++] = '.';
		(*map)[row][mapsize] = '\n';
		(*map)[row][mapsize + 1] = '\0';
		++row;
	}
}

void increase_map(char ***map, size_t mapsize)
{
	size_t iter;

	if (*map)
	{
		free((*map)[0]);
		free(*map);
	}
	if (!(*map = (char**)malloc(sizeof(char*) * (mapsize + 1))))
		error();
	if (!((*map)[0] = (char*)malloc(mapsize * (mapsize + 2))))
		error();
	iter = 1;
	while (iter < mapsize)
	{
		(*map)[iter] = (*map)[iter - 1] + mapsize + 2;
		++iter;
	}
	(*map)[mapsize] = NULL;
	fill_map(map, mapsize);
}

size_t prepare_map(char ***map, const t_shape *shapes)
{
	size_t min_points;
	size_t mapsize;

	min_points = ft_shapesize(shapes) * 4;
	mapsize = 1;
	while (mapsize * mapsize < min_points)
		++mapsize;
	increase_map(map, mapsize);
	return (mapsize);
}

void place(char **map, size_t row, size_t col, const t_shape *shape)
{
	size_t i;

	i = 0 - 1;
	while (++i < 4)
		map[row + shape->points[i].x][col + shape->points[i].y] = '#';
}

int place_or_remove(char **map, size_t mapsize, size_t row, size_t col,
					t_shape *shape, int flag)
{
	static int depth = 0;
	size_t i;

	i = 0 - 1;
	if (flag)
	{
		while (++i < 4)
			if (row + shape->points[i].x >= mapsize ||
				col + shape->points[i].y >= mapsize ||
				map[row + shape->points[i].x][col + shape->points[i].y] != '.')
				return (0);
		i = 0 - 1;
		while (++i < 4)
			map[row + shape->points[i].x][col + shape->points[i].y] = 'A' + depth;
		++depth;
		shape->is_place = 1;
	}
	else
	{
		--depth;
		while (++i < 4)
			map[row + shape->points[i].x][col + shape->points[i].y] = '.';
		shape->is_place = 0;
	}
	return (1);
}

t_shape *find_not_set_shape(const t_shape *shapes)
{
	if (!shapes)
		return (NULL);
	while (shapes && shapes->is_place)
		shapes = shapes->next;
	return ((t_shape*)shapes);
}

t_shape *find_set_shape(const t_shape *shapes)
{
	while (shapes && !shapes->is_place)
		shapes = shapes->next;
	return ((t_shape*)shapes);
}
/*
int fillit(char **map, size_t mapsize, t_shape *shapes)
{
	t_shape *shape;
	size_t row;
	size_t col;

	if (!(shape = find_not_set_shape(shapes)))
		return (1);
	row = 0 - 1;
	while (++row < mapsize)
	{
		col = 0 - 1;
		while (++col < mapsize)
		{
			if (place_or_remove(map, mapsize, row, col, shapes, 1))
			{
				if (fillit(map, mapsize, shapes->next))
					return (1);
				while (shapes)
				{
					shapes = find_not_set_shape(shapes);
					if (fillit(map, mapsize, shapes))
						return (1);
					shapes = shapes->next;
				}
				place_or_remove(map, mapsize, row, col, shape, 0);
				return (0);
			}
		}
	}
	return (0);
}
*/

int fillit(char **map, size_t mapsize, t_shape *shapes)
{
	t_shape *cur_shape;
	size_t row;
	size_t col;
	int flag;

	if (!shapes)
		return (1);
	flag = 1;
	cur_shape = shapes;
	while ((cur_shape = find_not_set_shape(cur_shape)))
	{
		flag = 1;
		row = 0 - 1;
		while (flag && ++row < mapsize)
		{
			col = 0 - 1;
			while (flag && ++col < mapsize)
			{
				if (place_or_remove(map, mapsize, row, col, cur_shape, 1))
				{
					if (fillit(map, mapsize, shapes))
						return (1);
					place_or_remove(map, mapsize, row, col, cur_shape, 0);
					flag = 0;
				}
			}
		}
		cur_shape = cur_shape->next;
	}
	if (!find_not_set_shape(shapes))
		return (1);
	return (0);
}

char **solve(t_shape *shapes)
{
	char **map;
	size_t mapsize;

	if (!shapes)
		return (NULL);
	map = NULL;
	mapsize = prepare_map(&map, shapes);
	while (!fillit(map, mapsize, shapes))
	{
		increase_map(&map, ++mapsize);
		fillit(map, mapsize, shapes);
	}
	return (map);
}
