/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_check.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:55:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/06/29 04:20:52 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_CHECK_H
# define FILLIT_CHECK_H
# include <time.h>
# include "./libft/includes/libft.h"

/*
**	PART 1. Figure and its derivatives
**		##
**		##
*/
# define F_1 "....\n....\n..##\n..##\n"

/*
**	PART 2. Figure and its derivatives
**		####
*/
# define F_2 "...#\n...#\n...#\n...#\n"
# define F_3 "....\n....\n....\n####\n"

/*
**	PART 3. Figure and its derivatives
**		##
**	   ##
*/
# define F_4 "....\n....\n..##\n.##.\n"
# define F_5 "....\n....\n.##.\n.##.\n"
# define F_6 "....\n...#\n..##\n..#.\n"
# define F_7 "....\n..#.\n..##\n...#\n"

/*
**	PART 4. Figure and its derivatives
**		#
**	   ##
**      #
*/
# define F_8 "....\n..#.\n..##\n..#.\n"
# define F_9 "....\n...#\n..##\n...#\n"
# define F_10 "....\n....\n..#.\n.###\n"
# define F_11 "....\n....\n.###\n..#.\n"

/*
**	PART 5. Figure and its derivatives
**		#
**	    #
**      ##
*/
# define F_12 "....\n....\n.#..\n.###\n"
# define F_13 "....\n....\n...#\n.###\n"
# define F_14 "....\n..#.\n..#.\n..##\n"
# define F_15 "....\n...#\n...#\n..##\n"
# define F_16 "....\n....\n.###\n.#..\n"
# define F_17 "....\n....\n.###\n...#\n"
# define F_18 "....\n..##\n...#\n...#\n"
# define F_19 "....\n..##\n..#.\n..#.\n"

/*
**  ERROR TETRAMINOS
*/
# define F_20 "...s\n....\n.#..\n.###\n"
# define F_21 "....\n....\n...\n.###\n"
# define F_22 ""
# define F_23 "####\n##..\n..##\n####\n"
# define F_24 "#...\n.#..\n..#.\n...#\n"
# define F_25 "###.\n.##.\n....\n....\n"

/*
**  option.c
*/
int			option(int flag, int fd);

/*
**  difficult.c
*/
void		hard_square_10(char ***figures, int fd);
void		hard_pipe_26(char ***figures, int fd);
void		hard_random_15_v1(char ***figures, int fd);
void		hard_random_12(char ***figures, int fd);
void		hard_random_15_v2(char ***figures, int fd);

#endif
