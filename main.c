/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:56:20 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/14 14:56:21 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdio.h"

#include "libft.h"

#include "shape.h"
#include "input.h"
#include "solve.h"

void	error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

 int	main(int argc, const char * const *argv)
{
	 int		iter;
	int		fd;
	t_shape *shapes;
	char	**map;

	iter = 0;
	while (++iter <= argc)
	{
		printf("arg: %s\n", argv[iter]);
		if ((fd = open(argv[iter], O_RDONLY)) == -1)
			error();
		write(1, "ok\n", 3);
		shapes = get_shapes(fd);
		map = solve(shapes);
		for (size_t i = 0; map[i]; ++i)
			printf("%s", map[i]);
		free(map[0]);
		free(map);
		ft_shapeclear(&shapes);
	}
	// for (int i = 0; i < argc; ++i)
	// 	printf("arg %i is %s\n", i, argv[i]);
	return (0);
}
