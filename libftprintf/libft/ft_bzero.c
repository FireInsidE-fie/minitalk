/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:55:05 by estettle          #+#    #+#             */
/*   Updated: 2024/10/01 10:56:52 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char	*melody = malloc(100);
	char	*roxy = malloc(100);

	printf("[!] Testing ft_bzero()...\n");
	bzero(melody, 3);
	ft_bzero(roxy, 3);
	printf("[Test 1] : %s\t%s\n", melody, roxy);
	ft_bzero(roxy, 0);
	printf("[Test 2] : %s\t%s\n", melody, roxy);
}
*/
