/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:28:29 by ymanilow          #+#    #+#             */
/*   Updated: 2019/08/12 13:44:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_point
{
	unsigned int		x;
	unsigned int		y;
}						t_point;

typedef struct			s_shape
{
	t_point				points[4];
	struct s_shape		*next;
	struct s_shape		*end;
	size_t				letter;
}						t_shape;

int						ft_check_shapes(char *s);
size_t					ft_input(int fd, t_shape **shapes);
char					**ft_map_create(size_t k);
int						ft_fillit(char ***map, t_shape *shapes,
											size_t map_size);
t_shape					*ft_list_new(t_shape *shapes);
int						ft_list_add_to_end(t_shape **list, t_shape *new);
void					ft_shapes_clear(t_shape *shapes);

#endif
