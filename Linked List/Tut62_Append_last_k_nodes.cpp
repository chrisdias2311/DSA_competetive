#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n=new node(val);

    //Corner case
    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
}
void display(node* head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


int length(node* head){
    int len=0;
    node* temp=head;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}


node* kappend(node* &head, int k){
    node* newHead;
    node* newTail;
    node* temp=head;

    int l=length(head);
    int count=1;

    while(temp->next!=NULL){
        if(count==l-k){
            newTail=temp;
        }
        if(count==l-k+1){
            newHead=temp;
        }
        temp=temp->next;
        count++;
    }
    newTail->next=NULL;
    temp->next=head;

    return newHead;
}

int main(){
    node* head=NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head,arr[i]);
    }
    cout<<"\n Original Linkedlist: ";
    display(head);

    node* newhead=kappend(head,3);
    cout<<"\n After appending last k nodes: ";
    display(newhead);

    return 0;
}











// class node{
//     public:

//     int data;
//     node* next;

//     node(int val){
//         data=val;
//         next=NULL;
//     }
// };



// void insertAtTail(node* &head, int val){
//     //Corner Case
    


//     node* n=new node(val);
//     if(head==NULL){
//         head=n;
//         return;
//     }

//     node* temp=head;

//     while(temp->next!=NULL){
//         temp=temp->next;
//     }

//     temp->next=n;
// }


// void display(node* head){
//     node* temp=head;

//     while(temp!=NULL){
//         cout<<temp->data<<"->";
//         temp=temp->next;
//     }
//     cout<<"NULL"<<endl;
// }



// int main(){
//     node* head=NULL;
//     insertAtTail(head,1);
//     insertAtTail(head,2);
//     insertAtTail(head,3);
//     insertAtTail(head,4);
//     insertAtTail(head,5);
//     insertAtTail(head,6);
//     display(head);

//     return 0;
// }