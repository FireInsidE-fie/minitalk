/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:46:30 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:46:32 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*area;
	size_t	b_size;

	b_size = count * size;
	area = malloc(b_size);
	if (!area)
		return (NULL);
	ft_bzero(area, b_size);
	return (area);
}
