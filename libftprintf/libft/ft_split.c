/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:47:48 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:47:49 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	clear_slices(char **slices)
{
	int	i;

	i = 0;
	while (slices[i])
		free(slices[i++]);
	free(slices);
	return (0);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;

	copy = malloc((n) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, n);
	copy[n - 1] = '\0';
	return (copy);
}

static char	**alloc_slices(char const *s, char c)
{
	int		i;
	int		slice_count;
	char	**slices;

	slice_count = 0;
	i = 0;
	if (!(*s))
	{
		slices = malloc(sizeof(char *));
		if (!slices)
			return (NULL);
		*slices = NULL;
		return (slices);
	}
	while (s[i] == c)
		i++;
	while (s && s[i])
	{
		if (s[i] == c)
			i++;
		else if (++slice_count)
			while (s[i] && s[i] != c)
				i++;
	}
	return (malloc((slice_count + 1) * sizeof(char *)));
}

int	slice(char **slices, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s && s[i])
	{
		while (s[i] == c)
			i++;
		s += i;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i > 0)
		{
			*(slices + j) = ft_strndup(s, i + 1);
			if (!*(slices + j++) && !clear_slices(slices))
				return (-1);
		}
	}
	slices[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**slices;

	slices = alloc_slices(s, c);
	if (!slices)
		return (NULL);
	if (!*s)
		return (slices);
	if (slice(slices, s, c) == -1)
		return (NULL);
	return (slices);
}
/*
#include <stdio.h>

int	main(void)
{
	//char	*invalidReadCheck;
	//invalidReadCheck = malloc(sizeof(char));
	char	**slices = ft_split("", 'a');
	printf("%s\n", slices[0]);
}
*/
