/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:40:27 by estettle          #+#    #+#             */
/*   Updated: 2024/10/25 15:43:41 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Gets the number of digits of an unsigned integer.
 *
 * @param nb The unsigned int to process.
 * @return The number of digits calculated.
 */
static int	get_uns_len(unsigned int nb)
{
	unsigned int	divider;
	int				digit_count;

	divider = 1;
	digit_count = 1;
	while ((nb / divider) >= 10)
	{
		divider *= 10;
		digit_count++;
	}
	return (digit_count);
}

/**
 * @brief Puts an unsigned integer to stdout.
 *
 * @param n The unsigned integer to print out.
 */
static void	ft_putuns(unsigned int n)
{
	if (n >= 10)
	{
		ft_putuns(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
}

/**
 * @brief Prints an unsigned integer to stdout, counting the number of bytes.
 *
 * @param nb The unsigned int to process.
 * @param count A pointer to the number of bytes written by ft_printf() so far.
 */
void	process_uns(unsigned int nb, int *count)
{
	ft_putuns(nb);
	*count += get_uns_len(nb);
}
