#include "binary_trees.h"
#include <stdio.h>

/**
 * heapify_up - Move a node up in the Max Heap to maintain the Max Heap property.
 * @heap: Pointer to the root of the Max Heap.
 * @node: Pointer to the node to be moved up.
 */
void heapify_up(heap_t **heap, heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		/* Swap the node with its parent */
		int temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	/* Update the root of the heap if needed */
	if (!node->parent)
		*heap = node;
}

/**
 * heap_insert - Insert a value into a Max Binary Heap while maintaining
 * the Max Heap property.
 * @root: Pointer to the root node of the Max Heap.
 * @value: Integer value to insert.
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = NULL;

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	parent = *root;
	while (parent->left || parent->right)
	{
		if (value <= parent->n)
		{
			if (parent->left)
				parent = parent->left;
			else
				break;
		}
		else
		{
			if (parent->right)
				parent = parent->right;
			else
				break;
		}
	}

	new_node->parent = parent;
	if (value <= parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Ensure the Max Heap property is maintained */
	heapify_up(root, new_node);

	return (new_node);
}
