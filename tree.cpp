/*
create node
traverse binary tree with width first (levelOrder)
traverse binary tree with depth first (3 variations)
insert node to BST (2 variations, iterative and recursion)
Find height of a binary tree
print left view of binary tree
check if it BST
max depth

*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
 
/* Link list node */
struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* newNode(int value){
    Node *n = new Node;
    n->left = n->right = NULL;
    n->val = value;
    return n;
}

//traverse binary tree with levelOrder (use queue)
void levelOrder (Node *root){ //Time, O(n), Space: O(1)(only has left child) -best, O(n) -worst, avg
    if (root == NULL) return;
    queue<Node *> Q;
    Q.push(root);
    while(!Q.empty()){
        Node *current = Q.front();
        cout << current->val<< " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}

void preorder (Node *root){ // Time: O(n)
    if(root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder (Node *root){ // Time: O(n)
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void inorderIterative (Node *root){ // Time: O(n)
    stack<Node*>s;
    Node *p = root;
    while(!s.empty() || p){
        while(p){
            s.push(p);
            p = p->left;
        }
        p = s.top(); s.pop();
        cout << p->val << " ";
        p = p->right;
    }
}

void postorder (Node *root){ // Time: O(n)
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

//insert node to BST
Node* insert(Node * root, int data) {
    if(root == NULL) {
        Node *newNode =  new Node;
        newNode->left = newNode->right = NULL;
        newNode->val = data;
        return newNode;
    }
    if(data > root->val){
        root->right = insert(root->right, data);
    }else if (data < root->val){
        root->left = insert(root->left, data);
    }
    return root;
}

// Insert node to BST
// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
Node* insertIterative(Node * root, int value) {
    Node *newNode = new Node;
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    if(root == NULL){
       root = newNode;
       return root;
    }
    Node *nd = root;
    Node *parent = root;
   
    while(nd!=NULL){
        parent = nd;
        if(value > nd->val){
            nd = nd->right;
        }else{
            nd = nd->left;
        }
    }
    if(value > parent->val){
        parent->right = newNode;
    }else{
        parent->left = newNode;
    }
    return root;
}


Node* minValueNode(Node* node) 
{ 
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
Node* deleteNode(Node *root, int key) 
{ 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->val) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->val) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            Node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->val = temp->val; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->val); 
    } 
    return root; 
} 

//Find height of a binary tree
int findHeight(Node *root){
    if (root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

//https://www.geeksforgeeks.org/print-left-view-binary-tree/
void leftViewHelper(Node *root, int level, int *maxLevel){
    if (root == NULL) return;
    if (level > *maxLevel){
        cout << root->val << " ";
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
bool isValid(Node *node, int *minval, int *maxval){
    if(node == nullptr) return true;
    if( (minval && node->val <= *minval) || (maxval && node->val >= *maxval))
        return false;
    return isValid(node->left, minval, &node->val) && isValid(node->right, &node->val, maxval);
}
bool isValidBST(Node* root) {
    return isValid(root, nullptr, nullptr);
}

int maxDepth(Node* node){
    if (node==NULL) 
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
    
        /* use the larger one */
        if (lDepth > rDepth) 
            return(lDepth+1);
        else return(rDepth+1);
    }
} 

int main(){
    Node *root = insert(nullptr, 3);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    inorderIterative(root);
    return 0;
}