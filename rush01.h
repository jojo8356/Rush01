/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:23:19 by johan             #+#    #+#             */
/*   Updated: 2025/07/19 19:55:26 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
#define RUSH01_H

typedef struct s_state
{
	int	lines[24][4];
	int	index;
	int	n;
}	t_state;

void	generate_grids(int *clues);
int		validate_grid(int grid[4][4], int *clues);
int		is_valid_grid(int grid[4][4]);
void	store_grid(int grid[4][4]);
void	print_grid(int grid[4][4]);
int		parse_input(char *str, int *clues);
int		count_visible(int *line);
void	heap_permute(int *arr, int size, t_state *s);

#endif