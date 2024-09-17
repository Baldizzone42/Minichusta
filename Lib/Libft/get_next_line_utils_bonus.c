/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:08:12 by jose-rig          #+#    #+#             */
/*   Updated: 2024/09/02 13:51:46 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_calloc(size_t count, size_t size)
{
	char		*result;
	size_t		i;

	i = 0;
	result = malloc(count * size);
	if (result != NULL)
	{
		while (i < size * count)
		{
			result[i] = 0;
			i++;
		}
	}
	return ((void *)result);
} */

int	ft_strlen_bonus(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == 0)
		return (&((char *)s)[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (char)c)
			return (((char *)s));
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_bonus(char *s1, const char *s2)
{
	char			*join;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_free(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}
