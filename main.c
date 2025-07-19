/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:07:45 by johan             #+#    #+#             */
/*   Updated: 2025/07/19 19:07:47 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	clues[16];

	if (argc != 2 || !parse_input(argv[1], clues))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	generate_grids(clues);
	return (0);
}
