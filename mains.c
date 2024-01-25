/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maverqui <maverqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:01:40 by maverqui          #+#    #+#             */
/*   Updated: 2024/01/23 20:01:53 by maverqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int buff_size = 8;
	char buff[8];
	int fd = open("text", 0);
	int bytesRead = read(fd, buff, buff_size);
	printf("%s\n", buff);
	close(fd);
	return (0);
}