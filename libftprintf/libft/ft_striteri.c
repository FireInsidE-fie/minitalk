/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:56:53 by estettle          #+#    #+#             */
/*   Updated: 2024/10/03 10:57:13 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, (s + i));
		i++;
	}
}
/*
#include <stdio.h>

void	ft_uppercase(unsigned int index, char *c)
{
	(void)index;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	void	(*f)(unsigned int, char *);
	char melody[100] = "Can. You. Hear. Me?";

	f = ft_uppercase;
	ft_striteri(melody, f);
	printf("%s\n", melody);
}
*/
