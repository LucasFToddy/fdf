/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:48:07 by lucas-do          #+#    #+#             */
/*   Updated: 2024/09/30 18:35:55 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*a;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (ft_strdup(""));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!a)
		return (ft_strdup(""));
	ft_bzero(a, (len_s1 + len_s2 + 1));
	ft_strlcat(a, s1, (len_s1 + 1));
	ft_strlcat(a, s2, (len_s1 + len_s2 + 1));
	return (a);
}
