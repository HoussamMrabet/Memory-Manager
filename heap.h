#ifndef HEAP_H
# define HEAP_H

#include <stdlib.h>

typedef struct s_block_memory
{
    void                    *leak;
    struct s_block_memory   *next;
}   t_block_memory;

void    *ft_malloc(t_block_memory **memory, size_t size);
void    ft_free(t_block_memory **memory);

#endif