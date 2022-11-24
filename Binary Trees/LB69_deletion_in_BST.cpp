#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->righ=NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    //basecase 
    if(root==NULL){
        root = new Node(d);
        return root;
    }
    if(d>root->data){
        //insert in right part 
        root->right = insertIntoBST(root->right, d);
    }else{
        root->left = insertIntoBST(root->left, d);
    }
}
void takeInput(Node* root){
    int data;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root, data);
        cin>>data
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);

    return 0;
}