/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:07 by estettle          #+#    #+#             */
/*   Updated: 2025/01/13 13:39:26 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_data(const char *pid, const char *data)
{
	int	i;
	int	target;

	target = ft_atoi(pid);
	while (*data)
	{
		i = 7;
		while (i >= 0)
		{
			if (((*data >> i--) & 1) == 0)
				kill(target, SIGUSR1);
			else
				kill(target, SIGUSR2);
			usleep(100);
		}
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
	signal(SIGUSR1, SIG_IGN);
	send_data(argv[1], argv[2]);
	return (0);
}
