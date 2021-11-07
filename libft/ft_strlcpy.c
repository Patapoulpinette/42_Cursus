#include "libft.h"

size_t  ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
    size_t  i;

    i = 0;
    if (dstsize == 0)
        return (ft_strlen(src));
    else
    {
        while (i < ft_strlen(src) && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}
