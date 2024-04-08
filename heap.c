#include "heap.h"

void    *ft_malloc(t_block_memory **memory, size_t size)
{
    void    *res;
    t_block_memory  *new;
    t_block_memory  *tmp;

    tmp = *memory;
    res = malloc(size);
    if (!res)
        return (NULL);
    new = (t_block_memory *)malloc(sizeof(t_block_memory));
    if (!new)
    {
        free(res);
        return (NULL);
    }
    new->leak = res;
    new->next = NULL;
    if (!tmp)
        *memory = new;
    else
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    return (res);
}

void    ft_free(t_block_memory **memory)
{
    t_block_memory  *to_free;
    t_block_memory  *to_hold;

    to_free = *memory;
    while (to_free)
    {
        to_hold = to_free->next;
        free(to_free->leak);
        free(to_free);
        to_free = to_hold;
    }
}