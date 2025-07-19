/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:13:21 by johan             #+#    #+#             */
/*   Updated: 2025/07/19 19:25:44 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	validate_row_left(int g[4][4], int *c, int i)
{
	int	tmp[4];
	int	j;

	j = -1;
	while (++j < 4)
		tmp[j] = g[i][j];
	return (count_visible(tmp) == c[8 + i]);
}

int	validate_row_right(int g[4][4], int *c, int i)
{
	int	tmp[4];
	int	j;

	j = -1;
	while (++j < 4)
		tmp[j] = g[i][3 - j];
	return (count_visible(tmp) == c[12 + i]);
}

int	validate_col_top(int g[4][4], int *c, int i)
{
	int	tmp[4];
	int	j;

	j = -1;
	while (++j < 4)
		tmp[j] = g[j][i];
	return (count_visible(tmp) == c[i]);
}

int	validate_col_bottom(int g[4][4], int *c, int i)
{
	int	tmp[4];
	int	j;

	j = -1;
	while (++j < 4)
		tmp[j] = g[3 - j][i];
	return (count_visible(tmp) == c[4 + i]);
}

int	validate_grid(int g[4][4], int *c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!validate_row_left(g, c, i)
			|| !validate_row_right(g, c, i)
			|| !validate_col_top(g, c, i)
			|| !validate_col_bottom(g, c, i))
			return (0);
		i++;
	}
	return (1);
}
