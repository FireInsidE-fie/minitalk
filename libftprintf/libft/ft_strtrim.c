/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:43:42 by estettle          #+#    #+#             */
/*   Updated: 2024/10/04 10:40:50 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_prefix_nb(char const *s1, char const *set)
{
	int	prefix_nb;
	int	i;

	prefix_nb = -1;
	while (s1[++prefix_nb])
	{
		i = -1;
		while (set[++i])
		{
			if (s1[prefix_nb] == set[i])
			{
				i = 0;
				break ;
			}
		}
		if (!set[i])
			break ;
	}
	return (prefix_nb);
}

static int	get_suffix_nb(char const *s1, char const *set)
{
	int	i;
	int	suffix_nb;
	int	s1_length;

	suffix_nb = -1;
	s1_length = ft_strlen(s1);
	if (!s1_length)
		return (0);
	while (s1[s1_length - ++suffix_nb - 1])
	{
		i = -1;
		while (set[++i])
		{
			if (s1[s1_length - suffix_nb - 1] == set[i])
			{
				i = 0;
				break ;
			}
		}
		if (!set[i])
			break ;
	}
	return (suffix_nb);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		s1_length;
	int		prefix_nb;
	int		suffix_nb;
	int		i;

	s1_length = ft_strlen(s1);
	prefix_nb = get_prefix_nb(s1, set);
	suffix_nb = get_suffix_nb(s1, set);
	if (s1_length - prefix_nb <= 0 && s1_length - suffix_nb <= 0)
	{
		trimmed = malloc(1);
		if (!trimmed)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = malloc((s1_length - prefix_nb - suffix_nb + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	i = -1;
	while (++i < s1_length - prefix_nb - suffix_nb && s1[i])
		trimmed[i] = s1[i + prefix_nb];
	trimmed[i] = '\0';
	return (trimmed);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("[Test 4] : %s\n", ft_strtrim("            ", " "));
}
*/
