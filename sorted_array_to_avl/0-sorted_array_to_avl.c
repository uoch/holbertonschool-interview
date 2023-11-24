#include "binary_trees.h"
/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	int mid;

	if (size == 0)
		return (NULL);
	root = malloc(sizeof(avl_t));
	if (root == NULL)
		return (NULL);
	mid = (size - 1) / 2;
	root->n = array[mid];
	root->parent = NULL;
	root->left = sorted_array_to_avl(array, mid);
	root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
	if (root->left != NULL)
		root->left->parent = root;
	if (root->right != NULL)
		root->right->parent = root;
	return (root);
}
