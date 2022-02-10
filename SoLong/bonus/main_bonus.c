/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:48:50 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 16:22:04 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	char	*ber;

	if (ac == 2)
	{
		ber = ft_strrchr(av[1], '.');
		if (ft_strrchr(av[1], '.') == NULL)
			print_error_bonus(NOT_VALID_FILE);
		if (ft_strncmp(".ber", ber) != 0)
			print_error_bonus(NOT_VALID_FILE);
		all_graphic_bonus(av);
	}
	else
		print_error_bonus(NO_USAGE);
	return (0);
}
