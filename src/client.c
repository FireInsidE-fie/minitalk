/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:07 by estettle          #+#    #+#             */
/*   Updated: 2024/11/24 20:11:43 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	process_ping(const int signum)
{
	(void)signum;
	write(1, "[!] - Ping back received!\n", 26);
}

int	main(const int argc, char **argv)
{
	signal(SIGUSR1, process_ping);
	if (argc != 2)
		return (-1);
	kill(ft_atoi(argv[1]), SIGUSR1);
	sleep(1);
	return (0);
}
