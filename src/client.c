/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:07 by estettle          #+#    #+#             */
/*   Updated: 2024/11/25 11:59:54 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ping_received(int signum)
{
	(void)signum;
	ft_printf("Ping back received!!\n");
}

void	send_char(char *pid, uint32_t character)
{
	int	i;
	int	target;

	i = 31;
	target = ft_atoi(pid);
	ft_printf("Sent : ");
	while (i >= 0)
	{
		if (((character >> i) & 1) == 0 && ft_printf("0"))
			kill(target,SIGUSR1);
		else if (ft_printf("1"))
			kill(target,SIGUSR2);
		i--;
		usleep(100);
	}
	ft_printf("\n");
}

void	send_data(char *pid, char *data)
{
	//write(1, "[!] - Ping received! Beginning data transfer...\n", 48);
	signal(SIGUSR1, ping_received);
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
	signal(SIGUSR1, ping_received);
	send_data(argv[1], argv[2]);
	usleep(50000);
	return (0);
}
