/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:00:27 by mpapin            #+#    #+#             */
/*   Updated: 2025/01/25 17:18:59 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	length;

	length = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	string = ft_calloc(length + ft_strlen(s2) + 1, sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, length + 1);
	while (*s2)
		string[length++] = *s2++;
	return (string);
}
