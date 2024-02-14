/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maverqui <maverqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:31:26 by maverqui          #+#    #+#             */
/*   Updated: 2024/02/14 17:48:15 by maverqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*full;

	j = 0;
	i = 0;
	if(!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	full = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!full)
		return (NULL);
	while (s1[i])
	{
		full[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		full[i + j] = s2[j];
		j++;
	}
	full[i + j] = '\0';
	free(s1);
	return (full);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_substr(const char *s, unsigned int start, size_t len)

{
	size_t	i;
	size_t	j;
	char	*new_s;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		while (j < len && s[start + j] != '\0')
			j++;
	new_s = malloc(sizeof(char) * j + 1);
	if (!new_s)
		return (NULL);
	while (i < j)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
