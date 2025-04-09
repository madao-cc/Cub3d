/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:51:19 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/02 20:51:27 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = init_cub();
	cub_parser(argc, argv, cub);
	prepare_the_game(cub);
	start_the_game(cub);
	return (0);
}
