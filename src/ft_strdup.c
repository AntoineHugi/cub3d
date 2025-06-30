#include "../inc/cub3d.h"

char	*ft_strdup(const char *s)
{
	int		src_size;
	int		i;
	char	*ptr;

	src_size = ft_strlen(s);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (src_size + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}