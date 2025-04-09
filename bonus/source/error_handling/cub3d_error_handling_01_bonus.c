/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_handling_01_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:43:20 by antfonse          #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

// PRINT ERROR MESSAGE, CLEAN MEMORY AND EXIT PROGRAM
void	print_error_exit(char *msg, char *info, t_data *cub_data)
{
	if (info)
		printf(ERR_COLOR"%s\n"ERR_MSG"%s: "ERR_INFO"%s"RESET"\n", MSG_ERROR, \
			msg, info);
	else
		printf(ERR_COLOR"%s\n"ERR_MSG"%s"RESET"\n", MSG_ERROR, msg);
	free(cub_data->cub);
	clean_parser(cub_data);
	exit(EXIT_FAILURE);
}

// PRINT ERROR MESSAGE (PERROR), CLEAN MEMORY AND EXIT PROGRAM
void	print_perror_exit(char *info, t_data *cub_data)
{
	if (info)
		printf(ERR_COLOR"%s\n"ERR_MSG"%s: "ERR_INFO"%s"RESET"\n", MSG_ERROR, \
		strerror(errno), info);
	else
		printf(ERR_COLOR"%s\n"ERR_MSG"%s"RESET"\n", MSG_ERROR, strerror(errno));
	free(cub_data->cub);
	clean_parser(cub_data);
	exit(EXIT_FAILURE);
}
