#include<iostream>
using namespace std;
#define n 100

class stack{
    int* arr;
    int top;

    public: 
    stack(){
        arr = new int[n];
        top=-1;
    }

    void push(int x){
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }

        top++;
        arr[top]=x;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
        }

        top--;
    }

    int peek(){
        if(top==-1){
            cout<<"No element in stack (Stack Underflow)"<<endl;
            return 0;
        }
        return arr[top];
    }

    void display(){
        for(int i=0; i<=top; i++){
            cout<<arr[i];
        }
    }
};

int main(){
    stack st;
    
    int choice;
    char condition;

    do {
        cout<<"Enter your choice: \n 1. Push \n 2.Pop \n 3.Peek \n 4.Display"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter a number to push in stack: ";
            int num;
            cin>>num;
            st.push(num);
            break;

        case 2:    
            st.pop();
            break;

        case 3:    
            st.peek();
            break;  

        case 4: 
            st.display();
            break;      
        
        default:
            break;
        }

        cout<<"\n Do you want to continue? (Y/n)";
        cin>>condition;

    } while (condition=='y' || condition=='Y');
    

    return 0;
}