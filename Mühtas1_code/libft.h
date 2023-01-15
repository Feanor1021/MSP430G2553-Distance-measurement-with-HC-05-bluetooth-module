#ifndef LIBFT_H
#define LIBFT_H

#include "math.h"
#include "stdlib.h"

//Basic libft functions from ecole 42
int     ft_strnstr(const char *haystack, const char *needle, int len);
int	ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, int n);
int	ft_strlcpy(char *dst, char *src, int dstsize);
void	*ft_memset(void *b, int c, int len);

//Extra functions
int     ft_hex2_dec(const char *s);
char    *ft_ftoa(float Dist);
#endif