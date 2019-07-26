/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 01:14:58 by sleonia           #+#    #+#             */
/*   Updated: 2019/06/29 05:32:03 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_check.h"

static char		**fill(void)
{
	char		**figures;

	figures = (char **)malloc(sizeof(char *) * 20);
	figures[0] = F_1;
	figures[1] = F_2;
	figures[2] = F_3;
	figures[3] = F_4;
	figures[4] = F_5;
	figures[5] = F_6;
	figures[6] = F_7;
	figures[7] = F_8;
	figures[8] = F_9;
	figures[9] = F_10;
	figures[10] = F_11;
	figures[11] = F_12;
	figures[12] = F_13;
	figures[13] = F_14;
	figures[14] = F_15;
	figures[15] = F_16;
	figures[16] = F_17;
	figures[17] = F_18;
	figures[18] = F_19;
	figures[19] = NULL;
	return (figures);
}

static void		choice(char *str, int fd)
{
	char		**figures;
	int			count;
	int			nbr;
	int			i;

	i = 0;
	count = ft_atoi(str);
	figures = fill();
	srand(time(NULL));
	while (i < count)
	{
		nbr = rand() % 19;
		ft_putstr_fd(figures[nbr], fd);
		if ((i + 1) != count)
			write(fd, "\n", 1);
		i++;
	}
	free(figures);
}

int				main(int ac, char **av)
{
	int			i;
	int			fd;

	i = 0;
	remove("sleonia.txt");
	fd = open("sleonia.txt", O_CREAT);
	system("chmod 777 sleonia.txt");
	fd = open("sleonia.txt", O_WRONLY);
	if (ac == 2 && ft_strcmp(av[1], "-h") == 0)
		return (option(1, fd));
	if (ac == 2 && ft_strcmp(av[1], "-d") == 0)
		return (option(3, fd));
	if (ac == 2 && ft_strcmp(av[1], "-e") == 0)
		return (option(4, fd));
	if (ac == 2 && ft_atoi(av[1]) > 0)
		choice(av[1], fd);
	else
		ft_putendl("\033[31mIllegal option. Use -h\033[0m");
	close(fd);
	return (0);
}
