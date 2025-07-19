/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:08:22 by johan             #+#    #+#             */
/*   Updated: 2025/07/19 19:55:57 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_grid(int grid[4][4])
{
	int	i;
	int	j;
	int	k;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			k = i + 1;
			while (k < 4)
			{
				if (grid[i][j] == grid[k][j])
					return (0);
				k++;
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	count_visible(int *line)
{
	int	i;
	int	max;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}
