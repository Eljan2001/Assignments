#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
int main(){
  struct Node* root = newNode(5);
  root->left = newNode(2);
  root->right = newNode(29);
  root->left->left = newNode(11);
  root->left->left->left = newNode(5);
  root->left->right = newNode(23);
  root->right->right = newNode(0);
  root->right->right->right = newNode(0);
  root->right->left = newNode(23);
  root->left->left->right = newNode(16);
  root->left->right->left = newNode(0);
  root->left->right->right = newNode(15);
  root->right->left->left = newNode(31);
  root->right->left->right = newNode(0);
  root->right->right->left = newNode(0);

  
  printf("maximum sum of tree nodes: %d",addNodes(root));

  return 0;
}
