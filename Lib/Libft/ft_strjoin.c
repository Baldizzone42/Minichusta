/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-rig <jose-rig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:50:30 by jose-rig          #+#    #+#             */
/*   Updated: 2024/09/10 12:06:35 by jose-rig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *dest, char const *src)
{
	size_t	dest_len;
	size_t	src_len;
	char	*ss;
	size_t	c;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	ss = (char *)malloc((dest_len + src_len + 1));
	c = 0;
	if (!ss)
		return (NULL);
	if(dest)
	{
		while (dest[c] != '\0')
		{
			ss[c] = dest[c];
			c++;
		}
	}
	while (src[c - dest_len] != '\0')
	{
		ss[c] = src[c - dest_len];
		c++;
	}
	ss[c] = '\0';
	return ((char *)ss);
}

/*int main()
{
    char const *src = "HolaMundoMun";
    char const *dest = "Mundo";
    printf("dest: %s\n", ft_strjoin(src,dest));
    return (0);
}*/