/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:17:03 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/20 09:10:06 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_tokens(char const *s, char sep)
{
	size_t	i;
	int		c;
	int		t;

	i = 0;
	c = 0;
	t = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		while (s[i] != '\0' && s[i] != sep)
		{
			c = 1;
			i++;
		}
		if (c == 1)
			t++;
		c = 0;
	}
	return (t);
}

static int	clean_array(char **a, size_t i, size_t len)
{
	size_t	k;

	a[i] = (char *) malloc(sizeof(char) * (len + 1));
	if (a[i] == NULL)
	{
		k = 0;
		while (a[k])
		{
			free(a[k]);
			k++;
		}
		free(a);
		return (1);
	}
	return (0);
}

static char	**start_str(const char *s, char **a, char sep)
{
	size_t	i;
	size_t	start;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		start = i;
		len = i;
		while (s[len] != sep && s[len] != '\0')
			len++;
		if (len - i == 0)
			return (a);
		if (clean_array(a, j, (len - i)))
			return (NULL);
		ft_strlcpy(a[j++], s + start, (len - i + 1));
		i = len;
	}
	return (a);
}

char	**ft_split(const char *s, char c)
{
	char	**a;
	int		t;

	if (!s)
		return (NULL);
	t = count_tokens(s, c);
	a = (char **)malloc(sizeof(char *) * (t + 1));
	if (!a)
		return (NULL);
	a = start_str(s, a, c);
	a[t] = NULL;
	return (a);
}
