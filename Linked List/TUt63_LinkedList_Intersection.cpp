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



void intersect(node* &head1, node* &head2, int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
int length(node* head){
    int len=0;
    node* temp=head;

    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
int intersection(node* &head1, node* &head2){
    int len1=length(head1);
    int len2=length(head2);

    int difference=0;
    node* ptr1;
    node* ptr2;
    
    if(len1>len2){
        difference=len1-len2;
        ptr1=head1;
        ptr2=head2;
    } else {
        difference=len2-len1;
        ptr1=head2;
        ptr2=head1;
    }


    while(difference){               //to set both the pointers at equal distance from the intersection point 
        ptr1=ptr1->next;
        if(ptr1=NULL){
            return -1;
        }
        difference--;
    }

    while(ptr1!=NULL && ptr2!=NULL){  //Check if both the pointers are pointing at same position
        if(ptr1->data==ptr2->data){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return -1;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;

    int arr[]={1,2,3,4,5,6,};
    for(int i=0;i<6;i++){
        insertAtTail(head1,arr[i]);
    }
    insertAtTail(head2, 9);
    insertAtTail(head2, 10);

    intersect(head1, head2, 3);
    display(head1);
    display(head2);
    
    cout<<"Intersection element is: ";
    cout<<intersection(head1, head2)<<endl;

    return 0;
}