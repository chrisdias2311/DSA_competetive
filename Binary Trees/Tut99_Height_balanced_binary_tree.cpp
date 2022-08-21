#include<iostream>
using namespace std;

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

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh);
}

//Time complexity = O(n^2) where n is the number of nodes in the tree 
// bool isBalanced(Node* root){

//     if(root==NULL){
//         return true;
//     }

    
//     if(isBalanced(root->left) == false){
//         return false;
//     }
//     if(isBalanced(root->right) == false){
//         return false;
//     }

//     int lHeight = height(root->left);
//     int rHeight = height(root->right);

//     if(abs(lHeight - rHeight) <=1){
//         return true;
//     } else {
//         return false;
//     }
// }


//Optimised solution with time complexity of O(n)
bool isBalanced(Node* root, int* height){
    if(root == NULL){
        return true;
    }


    int lh=0, rh=0;

    if(isBalanced(root->left, &lh)==false){
        return false;
    }
    if(isBalanced(root->right, &rh)==false){
        return false;
    }

    *height = max(lh, rh) + 1;
    if(abs(lh-rh)<=1){
        return true;
    } else {
        return false;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int height=0;
    
    //Checks if the binary tree is balanced or not 
    if(isBalanced(root, &height)==true){
        cout<<"Balanced Tree"<<endl;
    } else {
        cout<<"Unbalanced Tree"<<endl;
    }

    return 0;
}