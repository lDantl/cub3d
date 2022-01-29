#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
 int  i;
 char *b2;

 if (len == 0)
  return (b);
 i = 0;
 b2 = (char *)b;
 while (i != (int)len)
 {
  b2[i] = c;
  i++;
 }
 return (b);
}
