/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:19:27 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/20 09:11:34 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len_src);
	if (size < len_dst)
		return (size + len_src);
	if (size == len_dst)
		return (size + len_src);
	while ((i + len_dst) < (size - 1) && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

char	*ft_strdup(char *s)
{
	char	*a;
	size_t	i;
	size_t	len;

	if (!s || !*s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	a[0] = '\0';
	while (s[i])
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*a;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!a)
		return (NULL);
	ft_bzero(a, (len_s1 + len_s2 + 1));
	if (len_s1 == 0)
		s1[0] = '\0';
	ft_strlcat(a, s1, (len_s1 + 1));
	ft_strlcat(a, s2, (len_s1 + len_s2 + 1));
	free(s1);
	return (a);
}
