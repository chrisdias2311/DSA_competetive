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

int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}
int countSum(Node* root){
    if(root==NULL){
        return 0;
    }

    return countSum(root->left) + countSum(root->right) + root->data;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    ///Sum at Kth level 

    cout<<"Total number of nodes: "<< countNodes(root)<<"\n";
    cout<<"Sum of all the nodes: "<< countSum(root)<<"\n";

    return 0;
}