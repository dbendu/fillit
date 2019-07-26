/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 07:13:13 by sleonia           #+#    #+#             */
/*   Updated: 2019/06/29 13:36:50 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_check.h"

static void		help(void)
{
	ft_putendl("\033[33mHello, you reading man about fillit_check!\n\
Check sleonia.txt after command clicks!\n");
	ft_putendl("\033[36m./love_is -h           help you with fillit_check");
	ft_putendl("\033[32m./love_is [count]      enter a count of figures.");
	ft_putendl("\033[35m./love_is -d           difficult test.");
	ft_putendl("\033[31m./love_is -e           error tests.");
	system("echo \033[0m");
	ft_putstr("\n\033[36mIf you have any feedback and suggestions\
send them to telegram.\n\t\t\t\033[33m🦄🌈 Thanks you!🦄🌈\n\
\t\t   \033[35mhttps://t.me/Dream1ngFly\n\033[0m");
}

static void		difficult(int fd)
{
	char		**figures;
	int			nbr;

	figures = (char **)malloc(sizeof(char *) * 20);
	srand(time(NULL));
	nbr = rand() % 5;
	if (nbr == 0)
		hard_square_10(&figures, fd);
	else if (nbr == 1)
		hard_pipe_26(&figures, fd);
	else if (nbr == 2)
		hard_random_15_v1(&figures, fd);
	else if (nbr == 3)
		hard_random_12(&figures, fd);
	else if (nbr == 4)
			hard_random_15_v2(&figures, fd);
	else
		return ;
	free(figures);
}

static void		error(int fd)
{
	char		**figures;
	int			count;
	int			i;

	i = 0;
	figures = (char **)malloc(sizeof(char *) * 20);
	figures[0] = F_20;
	figures[1] = F_21;
	figures[2] = F_22;
	figures[3] = F_23;
	figures[4] = F_24;
	figures[5] = F_25;
	srand(time(NULL));
	count = rand() % 6 + 1;
	while (i < count)
	{
		ft_putstr_fd(figures[rand() % 6], fd);
		if ((i + 1) != count)
			write(fd, "\n", 1);
		i++;
	}
	free(figures);
}

int				option(int flag, int fd)
{
	if (flag == 1)
		help();
	else if (flag == 3)
		difficult(fd);
	else if (flag == 4)
		error(fd);
	return (0);
}
