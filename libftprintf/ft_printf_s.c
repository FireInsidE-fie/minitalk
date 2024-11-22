/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:51:18 by estettle          #+#    #+#             */
/*   Updated: 2024/10/27 21:06:29 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/**
 * @brief Prints a string to stdout, counting the number of bytes written.
 *
 * @param str The string to process.
 * @param count A pointer to the number of bytes written by ft_printf() so far.
 */
void	process_str(char *str, int *count)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		*count += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}
