
#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int	ft_atoi(const char *nptr);
int	count_tokens(char const *s, char sep);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dst, char *src, size_t size);

#endif