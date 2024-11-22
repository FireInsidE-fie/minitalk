/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:55:58 by estettle          #+#    #+#             */
/*   Updated: 2024/10/03 10:56:21 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		s_length;
	char	*result_s;

	i = 0;
	s_length = ft_strlen(s);
	result_s = malloc((s_length + 1) * sizeof(char));
	if (!result_s)
		return (NULL);
	while (i < s_length)
	{
		result_s[i] = f(i, s[i]);
		i++;
	}
	result_s[i] = '\0';
	return (result_s);
}
/*
#include <stdio.h>

char	ft_uppercase(unsigned int index, char c)
{
	(void)index;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	main(void)
{
	char	(*f)(unsigned int, char);

	f = ft_uppercase;

	printf("%s\n", ft_strmapi("Can. You. Hear. Me?", f));
}
*/
