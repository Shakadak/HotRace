#include <stdlib.h>
#include "hotrace.h"

void	ft_swap_node(t_btree *dest, t_btree *src)
{
	char	*tmp;

	tmp = dest->value;
	dest->value = src->value;
	free(tmp);
	tmp = NULL;
	free(src->keyword);
	src->keyword = NULL;
	free(src);
	src = NULL;
}
