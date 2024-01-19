#include "binary_trees.h"

int heap_extract(heap_t **root)
{
    heap_t *node = NULL;
    int value = 0;

    if (!root || !*root)
        return (0);
    node = *root;
    value = node->n;
    while (node->left || node->right)
    {
        if (!node->right || node->left->n > node->right->n)
        {
            node->n = node->left->n;
            node = node->left;
        }
        else if (!node->left || node->left->n < node->right->n)
        {
            node->n = node->right->n;
            node = node->right;
        }
    }
    if (node->parent->left == node)
        node->parent->left = NULL;
    else
        node->parent->right = NULL;
    free(node);
    return (value);
}