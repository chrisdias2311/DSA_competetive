// Limitations of arrays 
// -Fixed size
// -Contiguous block of memory
// -Inserting or deleting is costly

//Properties of linkedList 
//-Size can be modified 
//-Non-contiguous memory 
//-Insertion and deletion at any point is easier 
#include <iostream>
using namespace std;

//Insert at head 
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

//     node* n = new node(val);

//     //Corner case
//     //Head is null, i.e our linked list is empty 
//     if(head==NULL){
//         head = n;
//         return;
//     }

    

//     node* temp=head;
//     //To traverse till on the linked list
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }

//     temp->next=n;    //This becomed the second last node and hence we put the value of our new node in its next field;
// }

// void display(node* head){
//     node* temp = head;

//     while(temp!=NULL){
//         cout<<temp->data<<"->";
//         temp=temp->next;
//     }

//     cout<<"Null"<<endl;
// }

// int main(){

//     node* head=NULL;
//     insertAtTail(head, 1);
//     insertAtTail(head, 2);
//     insertAtTail(head, 3);
//     display(head);

//     return 0;
// }










//Insert at head 

class node{
    public:
    int data;           //value
    node* next;         //next pointer 

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;            //point the next of our new node to the head
    head=n;
}

void insertAtTail(node* &head, int val){

    node* n = new node(val);

    //Corner case
    //Head is null, i.e our linked list is empty 
    if(head==NULL){
        head = n;
        return;
    }
    

    node* temp=head;
    //To traverse till the end on the linked list
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;    //This becomed the second last node and hence we put the value of our new node in its next field;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;
}
void deletion(node* &head, int val){
    //cornerCase for empty linkedList
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }

    
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void display(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

    cout<<"Null"<<endl;
}

bool search(node* head, int key){
    node* temp= head;

    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

int main(){

    node* head=NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    display(head);
    cout<<"Search function called "+ search(head, 3)<<endl;
    deletion(head,3);
    display(head);

    return 0;
}