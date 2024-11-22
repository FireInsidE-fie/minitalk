/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:48:24 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:48:25 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (i < len && *haystack)
	{
		j = 0;
		while (j + i < len && haystack[j] && haystack[j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strnstr("Can. You. Hear. Me?", "", 30));
}
*/
