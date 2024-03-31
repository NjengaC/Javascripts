#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
 *  * binary_tree_height - Calculate the height of a binary tree
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: Height of the tree
 *      */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 *  * binary_tree_balance - Measure the balance factor of a binary tree
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: Balance factor of the tree
 *      */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	printf("L-%dR-%d\n", left_height, right_height);
	return (left_height - right_height);
}
