/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:47:39 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:47:40 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (dst);
	if (dst <= src)
		i = src - dst;
	else
		i = dst - src;
	if (i > len || src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i--)
			*(char *)(dst + i) = *(char *)(src + i);
	}
	return (dst);
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	void	*melody;
	void	*roxy = ft_strdup("123456");
	
	melody = roxy + 2;
	ft_memmove(melody, roxy, 4);
	write(1, (char *)melody, 4);
}
*/
