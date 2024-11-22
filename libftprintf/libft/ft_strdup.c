/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:47:59 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:48:00 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		str_length;
	char	*copy;
	int		i;

	str_length = (ft_strlen(s1) + 1) * sizeof(char);
	copy = malloc(str_length);
	if (!copy)
		return (NULL);
	i = 0;
	while (--str_length)
		copy[i++] = *(s1++);
	copy[i] = '\0';
	return (copy);
}
/*
int	main(void)
{
	ft_strdup("Can. You. Hear. Me?");
}
*/
