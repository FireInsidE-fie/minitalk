/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:58:59 by estettle          #+#    #+#             */
/*   Updated: 2024/10/27 21:13:39 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Puts a memory address to the standard input in the specified base.
 *
 * @param nb The number to print in uintptr_t (specific type for memory
 * addresses).
 * @param charset The charset for the base (length determines the base number).
 */
static void	ft_putnbr_base(uintptr_t nb, char *charset, int *count)
{
	unsigned short	base;

	base = ft_strlen(charset);
	if (nb >= base)
	{
		ft_putnbr_base(nb / base, charset, count);
		nb = nb % base;
	}
	if (nb < base)
	{
		(*count)++;
		ft_putchar_fd(charset[nb], 1);
	}
}

/**
 * @brief Prints a pointer's address to stdout.
 *
 * @param ptr The pointer to take the address of.
 * @param count A pointer to the number of bytes written by ft_printf() so far.
 */
void	process_ptr(void *ptr, int *count)
{
	uintptr_t	address;

	address = (uintptr_t)ptr;
	write(1, "0x", 2);
	*count += 2;
	if (!ptr)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	ft_putnbr_base(address, "0123456789abcdef", count);
}
