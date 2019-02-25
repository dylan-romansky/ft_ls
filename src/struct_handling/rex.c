#include "ls.h"

t_rex	*new_rex(t_direct *d)
{
	t_rex	*new;

	new = (t_rex *)malloc(sizeof(t_rex));
	new->dir = d;
	new->next = NULL;
	return (new);
}

void	add_rex(t_direct *d, t_rex **rec)
{
	t_rex	*curr;
	t_rex	*new;

	curr = *rec;
	if (!(curr->dir))
	{
		curr->dir = d;
		return ;
	}
	new = new_rex(d);
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	del_rex(t_rex *rec)
{
	t_rex	*del;

	del = rec;
	if (del->next)
		del_rex(del->next);
	free(del);
}
