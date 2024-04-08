#include "heap.h"

int	main(void)
{
	t_block_memory *memory;
	char	*str;
	char	*str1;
	int	i;

	i = 0;
	memory = NULL;
	str = ft_malloc(&memory, 6);
	while (i < 5)
	{
		str[i] = '#';
		i++;
	}
	str[i] = '\0';
	str1 = ft_malloc(&memory, 4);
	i = 0;
	while (i < 3)
	{
		str1[i] = '#';
		i++;
	}
	str1[i] = '\0';
	ft_free(&memory);
}