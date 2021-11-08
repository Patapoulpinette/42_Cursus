#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s) - 1;
    if (c == '\0' && s != 0)
        return (&s[ft_strlen(s) + 1]);
    while (i >= 0)
    {
        if (s[i] == c)
            return (&s[i]);
        i--;
    }
    return (0);
}