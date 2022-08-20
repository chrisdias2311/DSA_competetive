#include<iostream>
using namespace std;

// Algorithm
// 1. Start from the end of postorder & pick an element to create a node
// 2. Decrement postorder idx
// 3. Search for picked elements pos in inorder 
// 4. call to build right subtree from inorder's 0 to pos + 1
// 5. Call to build left subtree from 0 to pos-1 to n
// 6. Return the node 

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


int search(int inorder[], int start, int end, int val){
    for(int i=start; i<=end; i++){
        if(inorder[i] == val){
            return i;
        }
    }
    return -1;
}
Node* buildTree(int postorder[], int inorder[], int start, int end){
    static int idx = 4;

    if(start>end){
        return NULL;
    }

    int val = postorder[idx];
    idx--;
    Node* curr = new Node(val);

    if(start == end){
        return curr;
    }

    int pos = search(inorder, start, end, val);
    curr->right = buildTree(postorder, inorder, pos+1, end);
    curr->left = buildTree(postorder, inorder, start, pos-1);

    return curr;
}
void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }

    inorderPrint(root->left);
    cout<<root->data;
    inorderPrint(root->right);
}


int main(){
    int postOrder[] = {4,  2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    //Build tree 
    Node* root = buildTree(postOrder, inorder, 0, 4);
    inorderPrint(root);

    cout<<'\n';

    return 0;
}