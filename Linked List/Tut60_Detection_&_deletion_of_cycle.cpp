#include<iostream>
using namespace std;

//Based of Floyd's algorithm also known as hare and tortoise algorithm 

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

void display(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

    cout<<"Null"<<endl;
}


void makeCycle(node* &head, int pos){
    node* temp=head;
    node* startNode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }

    temp->next=startNode;
}
bool detectcycle(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}
void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);

    fast=head;
    while(slow->next != fast->next){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next=NULL;
}


int main(){

    node* head=NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    makeCycle(head,3);
    // display(head);
    cout<<"Before Removal= "<<detectcycle(head)<<endl;
    removeCycle(head);
    cout<<"After Removal= "<<detectcycle(head)<<endl;
    display(head);

    return 0;
}