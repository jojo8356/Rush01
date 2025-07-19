/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:38:08 by johan             #+#    #+#             */
/*   Updated: 2025/07/19 19:54:32 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

static void	copy_line(int dest[4], int src[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dest[i] = src[i];
		i++;
	}
}

int	rec_fill_grid(int depth, int grid[4][4], int lines[24][4], int *clues)
{
	int	i;

	i = 0;
	if (depth == 4)
	{
		if (is_valid_grid(grid) && validate_grid(grid, clues))
		{
			store_grid(grid);
			return (1);
		}
		return (0);
	}
	while (i < 24)
	{
		copy_line(grid[depth], lines[i]);
		if (rec_fill_grid(depth + 1, grid, lines, clues))
			return (1);
		i++;
	}
	return (0);
}

void	generate_grids(int *clues)
{
	t_state	s;
	int		arr[4];
	int		grid[4][4];
	int		i;

	i = 1;
	while (i < 5)
	{
		arr[i - 1] = i;
		i++;
	}
	s.index = 0;
	s.n = 4;
	heap_permute(arr, 4, &s);
	if (!rec_fill_grid(0, grid, s.lines, clues))
		write(1, "Error\n", 6);
}
