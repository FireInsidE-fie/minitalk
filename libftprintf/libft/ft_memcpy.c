/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:47:34 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:47:34 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*original;
	size_t	i;

	original = (void *)dst;
	if (!dst && !src)
		return (original);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (original);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*melody = "Can. You. Hear. Me?";
	char	*roxy = malloc(100);

	printf("%s\n", ft_memcpy(roxy, melody, 20));
	printf("%s\n%s\n", melody, roxy);

	printf("%s\n", ft_memcpy(roxy+5, melody, 20));
	printf("%s\n%s\n", melody, roxy);
}
*/
