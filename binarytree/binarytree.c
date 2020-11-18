#include <stdio.h>
#include <stdlib.h>

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


/*
 *     1
 *   5   10 
 * 20 4 21 20 
 *999  13   15
 * */

int main(){
  struct Node* root = newNode(1);
  root->left = newNode(5);
  root->right = newNode(10);
  root->left->left = newNode(20);
  root->left->left->left = newNode(13);
  root->left->right = newNode(4);
  root->right->right = newNode(20);
  root->right->right->right = newNode(15);
  root->right->left = newNode(21);
  root->left->right->right = newNode(999);
  
  printf("maximum sum of tree nodes: %d",addNodes(root));

  return 0;
}
