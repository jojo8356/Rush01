/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:15:18 by johan             #+#    #+#             */
/*   Updated: 2025/07/19 19:55:47 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	heap_permute(int *arr, int size, t_state *s)
{
	int	i;

	if (size == 1)
	{
		i = 0;
		while (i < s->n)
		{
			s->lines[s->index][i] = arr[i];
			i++;
		}
		s->index++;
		return ;
	}
	i = 0;
	while (i < size)
	{
		heap_permute(arr, size - 1, s);
		if (size % 2 == 1)
			swap(&arr[0], &arr[size - 1]);
		else
			swap(&arr[i], &arr[size - 1]);
		i++;
	}
}
