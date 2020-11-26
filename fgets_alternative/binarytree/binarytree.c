#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
struct Node{
  int value;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int value) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value; 
    node->left = NULL;
    node->right = NULL; 
    return (node); 
}


int addNodes(struct Node* iter)
{
  if (iter == NULL)
    return 0;
  if (addNodes(iter->right) > addNodes(iter->left))
  {
  	return iter->value + addNodes(iter->right);
  }
  else
  {
	return iter->value + addNodes(iter->left);
  }
}
