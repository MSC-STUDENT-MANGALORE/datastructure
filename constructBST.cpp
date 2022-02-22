#include<iostream>
using namespace std;
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}
void inorder(struct node *root) {
   if (root != NULL) {
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
   }
}
struct node* insertNode(struct node* node, int val) {
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}
int main() {
   struct node *root = NULL;
   root = insertNode(root, 7);
   insertNode(root, 90);
   insertNode(root, 100);
   insertNode(root, 10);
   insertNode(root, 20);
   insertNode(root, 18);
   insertNode(root, 200);
   insertNode(root, 150);
   cout<<"In-Order traversal of the Binary Search Tree is: ";
   inorder(root);
   return 0;
}