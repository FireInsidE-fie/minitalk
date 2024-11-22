/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:44:46 by estettle          #+#    #+#             */
/*   Updated: 2024/10/27 21:06:21 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// libft
# include "libft/libft.h"

// libraries
# include <stdarg.h> // for variadic functions and va_ helpers
# include <unistd.h> // for write()
# include <stdint.h> // for uintptr

// function prototypes
int		ft_printf(const char *format, ...);
void	process_str(char *str, int *count);
void	process_dec(int nb, int *count);
void	process_uns(unsigned int nb, int *count);
void	process_hex(unsigned int nb, int *count, int is_uppercase);
void	process_ptr(void *ptr, int *count);

#endif
