#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t  i;
    char    *source;
    char    *dest;

    i = 0;
    source = (char *)src;
    dest = (char *)dst;
    if (dest < source)
    {
        while (i < len)
        {
            dest[i] = source [i];
            i++;
        }
    }
    else if (source < dest)
    {
        while (len >= 0)
        {
            dest[len - 1] = source[len - 1];
            len--;
        }
    }
    return (dst);
}

int main()
{
    char *source = 0;
    char destination[] = "Je suis une truite";
    
    ft_memmove(destination, source, 8);
    return 0; 
}