/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:12:05 by jose-rig          #+#    #+#             */
/*   Updated: 2024/09/11 15:51:04 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	n;

	n = 0;
	if (dst == NULL && src == NULL && len != 0)
		return (NULL);
	if (src < dst)
	{
		n = len;
		while (n > 0)
		{
			n--;
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		}
	}
	else
	{
		n = 0;
		while (n < len)
		{
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
			n++;
		}
	}
	return (dst);
}
