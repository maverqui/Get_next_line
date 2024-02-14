/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maverqui <maverqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:49:11 by maverqui          #+#    #+#             */
/*   Updated: 2024/02/12 16:07:37 by maverqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFFER_SIZE 8

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
int	ft_strlen(const char *str);

#endif