#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    if (c == '\0' && s != 0)
        return (&s[ft_strlen(s) + 1]);
    while (s[i])
    {
        if (s[i] == c)
            return (&s[i]);
        i++;
    }
    return (0);
}