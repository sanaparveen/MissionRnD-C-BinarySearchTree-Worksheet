/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node* convert_to_bst(struct node *head, int *arr, int first, int last);
struct node* insert_node(int data);

struct node * convert_array_to_bst(int *arr, int len)
{

    if (len <= 0 || arr == NULL)return NULL;

	struct node *head = NULL;

    head = convert_to_bst(head, arr, 0, len - 1);
	return head;
}
struct node* convert_to_bst(struct node *head, int *arr, int first, int last)
{

	if (first > last) return NULL;

	int mid = (first + last) / 2;

	head = insert_node(arr[mid]);
	head->left = convert_to_bst(head, arr, first, mid - 1);
	head->right = convert_to_bst(head, arr, mid + 1,  last);

	return head;
}

struct node* insert_node(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data  = data;
	temp->left  = NULL;
	temp->right = NULL;

	return temp;
}


