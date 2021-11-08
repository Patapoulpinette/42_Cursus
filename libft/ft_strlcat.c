#include "libft.h"

size_t  ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = ft_strlen(dst);
    if (dstsize == 0)
        return (ft_strlen(src));
    else
    {
        while (j < dstsize - 1)
        {
            dst[j] = src[i];
            i++;
            j++;
        }
    }
    dst[j] = '\0';
    return (ft_strlen(src));
}