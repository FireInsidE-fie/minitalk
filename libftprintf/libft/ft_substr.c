/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:10:20 by estettle          #+#    #+#             */
/*   Updated: 2024/10/03 10:52:59 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (start >= ft_strlen(s) + 1)
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) - start < len)
		substring = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	else
		substring = ft_calloc(len + 1, sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	s += start;
	while (i < len && s[i])
	{
		substring[i] = s[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
