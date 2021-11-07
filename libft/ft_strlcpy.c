#include "libft.h"

size_t  ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
    size_t  i;

    i = 0;
    if (dstsize == 0)
        return (0);
    else
    {
        while (i != '\0' && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
    }
    dst[i] = '\0';
    return (i);
}