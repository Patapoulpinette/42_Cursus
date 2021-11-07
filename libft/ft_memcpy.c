#include "libft.h"

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    size_t i;
    char *source;
    char *destination;

    i = 0;
    source = (char *)src;
    destination = (char *)dst;
    if (source == 0 || destination == 0)
        return (0);
    while (i < n)
    {
        destination[i] = source[i];
        i++;
    }
    return (dst);
}