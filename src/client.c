/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:07 by estettle          #+#    #+#             */
/*   Updated: 2024/11/25 10:25:40 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_char(char *pid, uint32_t character)
{
	int	i;
	int	target;

	i = 0;
	target = ft_atoi(pid);
	while (i < 32)
	{
		if (((character >> i) | 1) == 0)
			kill(SIGUSR1, target);
		else
			kill(SIGUSR2, target);
		i++;
	}
}

void	send_data(char *pid, char *data)
{
	write(1, "[!] - Ping received! Beginning data transfer...\n", 47);
	while (*data)
	{
		send_char(pid, *data);
		data++;
	}
}

int	main(const int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Correct usage : ./client <server pid> <data to send>\n");
		return (-1);
	}
	send_data(argv[1], argv[2]);
	return (0);
}
