/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void swap(struct node **node1, struct node **node2);

void correct_bst(struct node * root, struct node **first, struct node **last, struct node **prev)
{
	if (root)
	{

		correct_bst(root->left, first, last, prev); //left sub tree

		if (*prev != NULL && (*prev)->data > root->data)
		{
			if (!(*first))
			{
				*first = *prev;
				*last = root;
			}
			else
				*last = root;
		}

		*prev = root;
		correct_bst(root->right, first, last, prev); //right subtree
	}

}
void fix_bst(struct node *root){

	if (root == NULL) return;

	struct node *first = NULL, *last = NULL, *prev = NULL;


	correct_bst(root, &first, &last, &prev); //find the two nodes

	if (last != NULL && first != NULL) //fix the tree
		swap(&first, &last);
}

void swap(struct node **node1, struct node **node2)
{
	int temp = (*node1)->data;
	(*node1)->data = (*node2)->data;
	(*node2)->data = temp;
}
