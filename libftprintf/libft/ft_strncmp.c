/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:48:17 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:48:20 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_strncmp()
 * compares a string and returns the difference, either the ascii offset
 * or the strlen offset depending on if a difference is found inside the strings
 * or not
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	if (i < n && (!s1[i] || !s2[i]))
		return (ft_strlen(s1) - ft_strlen(s2));
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", ft_strncmp("abcdef", "abcdefghijklmnop", 6));
	printf("%d\n", strncmp("abcdef", "abcdefghijklmnop", 6));

	printf("%d\n", ft_strncmp("teste", "testex", 6));
	printf("%d\n", strncmp("teste", "testex", 6));
}
*/
