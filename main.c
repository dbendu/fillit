/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:16:08 by dbendu            #+#    #+#             */
/*   Updated: 2019/08/12 13:45:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_map_create(size_t map_size)
{
	unsigned	row;
	unsigned	col;
	char		**map;

	map = (char**)malloc(sizeof(char*) * (map_size + 1));
	map[0] = (char*)malloc(map_size * (map_size + 2));
	row = 0;
	while (++row < map_size)
		map[row] = map[row - 1] + map_size + 2;
	row = 0 - 1;
	while (++row < map_size)
	{
		col = 0 - 1;
		while (++col < map_size)
			map[row][col] = '.';
		map[row][map_size] = '\n';
		map[row][map_size + 1] = '\0';
	}
	map[map_size] = NULL;
	return (map);
}

const char colors[13][12] =
{
	"\e[38;5;001m", "\e[38;5;002m", "\e[38;5;003m",
	"\e[38;5;004m", "\e[38;5;005m", "\e[38;5;006m",
	"\e[38;5;011m", "\e[38;5;013m", "\e[38;5;014m",
	"\e[38;5;042m", "\e[38;5;046m", "\e[38;5;082m",
	"\e[38;5;225m"
};

void		print_map(char **map, size_t map_size)
{
	size_t x;
	size_t y;

	x = 0 - 1;
	while (++x < map_size)
	{
		y = 0 - 1;
		while (++y < map_size)
		{
			if (map[x][y] == '.')
			{
				write(1, ".", 1);
				continue;
			}
			write(1, colors[(map[x][y] - 'A') % 13], 11);
			write(1, &(map[x][y]), 1);
			write(1, "\e[0m", 4);
		}
		write(1, "\n", 1);
	}
}

void		ft_do_fillit(t_shape *shapes, size_t points)
{
	size_t	map_size;
	char	**map;

	map_size = 1;
	while (map_size * map_size < points)
		++map_size;
	map = ft_map_create(map_size);
	while (!(ft_fillit(&map, shapes, map_size)))
	{
		free(map[0]);
		free(map);
		map = ft_map_create(++map_size);
	}
	print_map(map, map_size);
}

int			main(int argc, const char *const *argv)
{
	int			fd;
	t_shape		*shapes;
	size_t		shapes_count;

	if (argc != 2)
	{
		write(1, "One file must been in arguments.\n", 34);
		write(1, "Example: ./fillit file_name\n", 29);
		return (0);
	}
	if (((fd = open(argv[1], O_RDONLY)) == -1))
		error("Can't open the file", 1);
	shapes = NULL;
	shapes_count = ft_input(fd, &shapes);
	close(fd);
	if (!shapes_count || shapes_count > 26)
	{
		printf("%zu\n", shapes_count);
		error("Invalid amount of shapes", 1);
	}
	ft_do_fillit(shapes, shapes_count * 4);
	ft_shapes_clear(shapes);
	return (0);
}
