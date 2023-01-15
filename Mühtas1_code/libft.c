#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

int ft_strnstr(const char *haystack, const char *needle, int len)
{
	unsigned int	counter;
	unsigned int	len_needle;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return (0);
	if (len == 0)
		return (0);
	counter = 0;
	while (counter <= (len - len_needle) && haystack[counter] != '\0')
	{
		if (ft_strncmp(&haystack[counter], needle, len_needle) == 0)
			return (counter);
		counter++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int		dif;
	int	i;

	i = 0;
	dif = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		dif = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (dif != 0)
			break ;
		i++;
	}
	return (dif);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

void	*ft_memset(void *b, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int     ft_hex2_dec(const char *s)
{
  unsigned int   num = 0;
  int   i = -1;
  
  while (++i < 4)
  {
    if(*s-48 < 10)
      num = (*s-48) + num * 16;
    else
      num = (*s-55) + num * 16;
    s++;
  }
  return (num);
}

char    *ft_ftoa(float Dist)
{
  char *array = (char *)malloc(sizeof(char)*8);
  int num = 0;
  int i = 0;
  
  num = (int)Dist;
  while(i<3)
  {
    array[2-i]=num % 10 + 48;
    num /= 10;
    i++;
  }
  num = (int)(fmod(Dist,1)*1000);
  array[3] = '.';
  i = 0;
  while(i<3)
  {
    array[6-i]=num%10 + 48;
    num /= 10;
    i++;
  }
  array[7]=0;
  return (array);
}