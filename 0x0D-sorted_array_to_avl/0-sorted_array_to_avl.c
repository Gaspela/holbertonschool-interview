#include "binary_trees.h"
/**
* binary_tree_node - binary tree nodes
* @parent: pointer first element of the array
* @size: is the number of element in the array
* Return: the new node
*/
avl_t  *binary_tree_node(avl_t  *parent, int size)
{
	avl_t  *new;

	new = malloc(sizeof(avl_t ));
	if (new == NULL)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->n = size;
	new->parent = parent;
	return (new);
}
/**
* insert_node - function that build an AVL tree from an array
* @array: array to be converted
* @start: first element array index
* @end: last element array to eval
* @parent: pointer element the new node of the array
* Return: binary tree, NULL
*/
avl_t *insert_node(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *root;
	size_t middle ;

	middle  = (start + end) / 2;
	root = binary_tree_node(parent, array[middle ]);
    
	if (root == NULL)
		return (NULL);
	if (start > end)
		return (NULL);
	if (middle  != start)
		root->left = insert_node(array, start, middle  - 1, root);
	if (middle  != end)
		root->right = insert_node(array, middle  + 1, end, root);

	return (root);
}
/**
* sorted_array_to_avl - builds an AVL tree from an array
* @array: array to be converted
* @size: number of elements in the arra
* Return: pointer to the root node
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (array == NULL || size == 0)
		return (NULL);
	root = insert_node(array, 0, size - 1, NULL);
	return (root);
}