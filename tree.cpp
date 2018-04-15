/* Program to insert in a sorted list */
#include<iostream>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value){
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
// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
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

Node * insert1(Node * root, int value) {
{
    if(root == NULL) {
        Node *newNode =  new Node;
        newNode->left = newNode->right = NULL;
        newNode->data = data;
        return newNode;
    }
    if(data > root->data){
        root->right = insert(root->right, data);
    }else if (data < root->data){
        root->left = insert(root->left, data);
    }
    return root;
}

//https://www.geeksforgeeks.org/print-left-view-binary-tree/
void leftViewHelper(Node *root, int level, int *maxLevel){
    if (root == NULL) return;
    if (level > *maxLevel){
        cout << root->data << " ";
        *maxLevel = level;
    }
    leftViewHelper(root->left, level+1, maxLevel);
    leftViewHelper(root->right, level+1, maxLevel);
}
void leftView(Node *root)
{
    int maxLevel = 0;
    leftViewHelper(root, 1, &maxLevel);
}

//https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
bool isBSTUtil(Node *root, int min, int max){// allow duplicate
    if (root == NULL) return true;
    return (root->data >= min && root->data <= max
    && isBSTUtil(root->left, min, root->data)
    && isBSTUtil(root->right, root->data, max));
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}


int main(){
	return 0;
}