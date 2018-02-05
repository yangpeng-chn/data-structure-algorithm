/* Program to insert in a sorted list */
#include<iostream>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value){
	node *n = new Node;
    n->left = n->right = NULL;
    n->data = value;
    return n;
}

//insert node to BST
Node * insert(Node * root, int value) {
   if (root == NULL) return newNode(value);
    if(value < root->data){
        root->left = insert(root->left, value);
    }else{
        root->right = insert(root->right, value);
    }
   return root;
}

// Insert node to BST
Node * insert(Node * root, int value) {
	Node *newNode = new node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    if(root == NULL){
       root = newNode;
       return root;
    }
    Node *nd = root;
    Node *parent = root;
   
    while(nd!=NULL){
        parent = nd;
        if(value > nd->data){
            nd = nd->right;
        }else{
            nd = nd->left;
        }
    }
    if(value > parent->data){
        parent->right = newNode;
    }else{
        parent->left = newNode;
    }
    return root;
}

int main(){
	
	
	return 0;
}