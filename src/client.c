/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:07 by estettle          #+#    #+#             */
/*   Updated: 2024/11/23 14:38:16 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	process_ping(const int signum)
{
	ft_printf("[!] - Ping back (%d) received!", signum);
}

int	main(const int argc, char **argv)
{
	signal(SIGUSR2, process_ping);
	if (argc != 2)
		return (-1);
	kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
