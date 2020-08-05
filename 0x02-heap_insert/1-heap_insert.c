#include "binary_trees.h"
/**
 * heap_start - finds and inserts a new Node.
 * @node: node to start.
 * Return: node.
 */
heap_t *heap_start(heap_t *node)
{
	int temp;

	if (!node || !node->parent)
		return (node);

	while (node->parent)
	{
		if (node->n < node->parent->n)
			return (node);

		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}
/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree:  pointer to the root node of the tree to measure the height.
 * Return: height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_height(tree->left) +
			binary_tree_height(tree->right));
}
/**
 * heap_insert - Function that inserts a value into a Max Binary Heap.
 * @root: is a double pointer to the root node of the Heap.
 * @value: iis the value store in the node to be inserted.
 * Return: pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int i = 0;
	heap_t *node = *root, *new_node;
	ssize_t n = binary_tree_height(*root) + 1;

	new_node = binary_tree_node(node, value);

	if (!new_node)
		return (NULL);

	if (!*root)
		return (*root = new_node);

	while (1 << (i + 1) <= n)
		i++;

	for (i--; i > 0; i--)
	{
		if (n & (1 << i))
			node = node->right;
		else
			node = node->left;
	}

	if (n & 1)
		node->right = new_node;
	else
		node->left = new_node;
	new_node->parent = node;

	return (heap_start(new_node));
}
