/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_01_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:20:44 by antfonse          #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

// CHECK IF STRING WAS DUPLICATED
char	*check_strdup(char *str, t_data *cub_data)
{
	char	*str2;

	str2 = ft_strdup(str);
	if (!str2)
		print_error_exit(MSG_MALLOC, NULL, cub_data);
	return (str2);
}

// SPLIT LINE INTO ARGUMENTS WITH ERROR HANDLING AND NUMBER OF ARGUMENTS CHECK
char	**check_split(char *str, char c, int n_args, t_data *cub_data)
{
	int		i;

	cub_data->args = free_str_array2d(cub_data->args);
	cub_data->args = ft_split(str, c);
	if (!cub_data->args)
		print_error_exit(MSG_LINE_SPLIT, cub_data->line, cub_data);
	i = 0;
	while (cub_data->args[i])
		i++;
	if (i != n_args)
		print_error_exit(MSG_LINE_ARGS, cub_data->line, cub_data);
	return (cub_data->args);
}

// CHECK IF STR WAS CREATED
char	*check_str(size_t len, t_data *cub_data)
{
	char	*str;

	str = (char *)malloc(len * sizeof(char));
	if (!str)
		print_error_exit(MSG_MALLOC, NULL, cub_data);
	return (str);
}

// CHECK IF ARRAY OF STRs WAS CREATED
char	**check_str_array(size_t len, t_data *cub_data)
{
	char	**str_array;

	str_array = (char **)malloc(len * sizeof(char *));
	if (!str_array)
		print_error_exit(MSG_MALLOC, NULL, cub_data);
	return (str_array);
}
