/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int min_node(int node1, int node2)
{
	return (node1 < node2) ? node1 : node2;
}

int closest_down(struct node *root)
{
	if (root == NULL)return MAX;
	return ((root->left == NULL) && (root->right == NULL)) ? 0 : (min_node(closest_down(root->left), closest_down(root->right)) + 1);
}

int find_closest(struct node *root, char node, int *found, int level, int *index)
{
	if (root == NULL)return MAX;
	if (root->data == node)
	{
		*found = 1;
		*index = level;
		return closest_down(root);
	}
	if ((root->left == NULL) && (root->right == NULL))
		return 0;

	int dist1 = find_closest(root->left, node, found, level + 1, index);
	if (*found)
		return min_node((closest_down(root->right) + ((*index) - level)) + 1, dist1);
	int dist2 = find_closest(root->right, node, found, level + 1, index);
	if (*found)
		return min_node((dist1 + ((*index) - level)) + 1, dist2);
	return min_node(dist1, dist2) + 1;
}


int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (!root || !temp) return -1;
	char node = temp->data;
	int found = 0,index = -1;

	int result = find_closest(root, node, &found, 0, &index);

	if (found) return result;
	return -1;
}