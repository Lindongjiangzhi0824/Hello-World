#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* left;
  Node* right;

  Node(int val)
  {
    data = val;

    left = right = NULL;
  }

  
};
void printPostorder(Node* node)
{
  //"bottom - up"
  if(node == NULL)
  {
    return;
  }
  printPostorder(node->left);
  printPostorder(node->right);
  cout<<node->data<<" ";
}
void printInorder(Node* node)
{
  if(node == NULL)
  {
    return;
  }
  printInorder(node->left);

  cout<<node->data<<" ";

  printInorder(node->right);
}
void printPreorder(Node* node)
{
  if(node == NULL)
  {
    return;
  }
  cout<<node->data<<" ";

  printPreorder(node->left);
  printPreorder(node->right);
}
void InorderTraversalNoRecur(Node* root)
{
  stack<Node *> s;
  Node* curr = root;

  while(curr != NULL || s.empty() == false)
  {
    while (curr != NULL)
    {
      s.push(curr);
      curr = curr->left;
    }
    
    curr = s.top();
    s.pop();

    cout<<curr->data<<" ";

    curr = curr->right;
  }
}
void inOrder(Node* root)
{
  stack<Node*> s;
  Node* curr = root;
  while(curr != NULL || s.empty() == false)
  {
    while(curr != NULL)
    {
      s.push(curr);
      curr = curr->left;
    }

    curr = s.top();
    cout<<curr->data<<" ";
    s.pop();

    curr = curr->right;
  }
}
int main()
{
  /*Creat root*/
  Node* root = new Node(1);
  /* following is the tree after above statement
 
             1
            / \
        NULL   NULL
  */
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);

  printPostorder(root);
  cout<<endl;

  printInorder(root);
  cout<<endl;
  
  printPreorder(root);
  cout<<endl;

  // InorderTraversalNoRecur(root);
  inOrder(root);
  cout<<endl;
  
  return 0;
}