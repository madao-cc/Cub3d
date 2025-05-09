/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antfonse <antfonse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:48:03 by antfonse          #+#    #+#             */
/*   Updated: 2024/04/22 20:48:05 by antfonse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function f to each character of string s, creating a new string.
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	char			*str;
	unsigned int	i;

	s_len = ft_strlen(s);
	str = (char *)malloc((s_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
