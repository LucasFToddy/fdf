/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:00:36 by lucas-do          #+#    #+#             */
/*   Updated: 2024/09/30 18:32:20 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*a;
	size_t	i;
	size_t	len;

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
