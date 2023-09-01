#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify - Heapifies a binary tree.
 *
 * @node: Pointer to the root node of the tree to heapify.
 */
void heapify(heap_t *node)
{
	heap_t *largest = node;

	if (node == NULL)
		return;

	if (node->left != NULL && node->left->n > largest->n)
		largest = node->left;

	if (node->right != NULL && node->right->n > largest->n)
		largest = node->right;

	if (largest != node)
	{
		int tmp = node->n;

		node->n = largest->n;
		largest->n = tmp;
		heapify(largest);
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *parent;

	if (root == NULL)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = node;
		return (node);
	}

	parent = *root;

	while (parent->left != NULL || parent->right != NULL)
	{
		if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
		{
			if (parent->left != NULL)
				parent = parent->left;
			else
				break;
		}
		else
		{
			if (parent->right != NULL)
				parent = parent->right;
			else
				break;
		}
	}

	if (parent->left == NULL)
		parent->left = node;
	else
		parent->right = node;

	node->parent = parent;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		int tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}

	return (node);
}
