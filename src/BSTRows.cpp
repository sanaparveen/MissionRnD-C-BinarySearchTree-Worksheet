/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int get_height_tree(struct node *root)
{
	if (root == NULL) return 0;

	int left_height  = get_height_tree(root->left);
	int right_height = get_height_tree(root->right);

	return (left_height > right_height) ? left_height + 1 : right_height + 1; 

}


void right_to_left_row(struct node *root, int *result, int *index, int row)
{
	if (root == NULL) return;

	if (row == 1)
	{
		result[*index] = root->data;
		*index = *index + 1;
	}
	else
	{
		right_to_left_row(root->right, result, index, row - 1);
		right_to_left_row(root->left, result, index, row - 1);

	}
}

int* BSTRighttoLeftRows(struct node *root)
{	
	if (root == NULL) return NULL;

	int height = get_height_tree(root),
    *result = (int *)malloc(height * sizeof(int)),
	index = 0, row = 1;

	while (row <= height)
		right_to_left_row(root, result, &index, row++);

	return result;
}


