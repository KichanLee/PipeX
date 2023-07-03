#include <stdio.h>
size_t	ft_strlen_a(const char *ch)
{
	size_t	i;

	i = 0;
	while (ch[i])
		++i;
	return (i);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t l)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen_a(s2);
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && i < l)
	{
		if (s1[i] == s2[j])
			j++;
		else if (s1[i] != s2[j])
		{	
			i -= j;
			j = 0;
		}
		++i;
		if (len == j)
			return ((char *)&s1[i - len]);
	}
	return (0);
}

int main()
{
    char *str = "PATH=/Users/kichan";
    char *th = "PATH";

    char *re  =ft_strnstr(str, th, ft_strlen_a(str));

    printf("%s", re);

}