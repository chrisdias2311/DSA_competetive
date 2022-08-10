#include<iostream>
using namespace std;
#define n 20

class queue{
    int* arr;
    int front;
    int rear;

    public:
    queue(){
        arr= new int[n];
        front=-1;
        rear=-1;
    }

    void enqueue(int x){
        if(rear==n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        rear++;
        arr[rear]=x;

        if(front==-1){
            front++;
        }
    }

    void dequeue(){
        if(front==-1 || front>rear){
            cout<<"No elements in Queue";
            return;
        }
        front++;
    }

    int peek(){               
        if(front==-1 || front>rear){
            cout<<"No elements in Queue";
            return -1;
        }

        return arr[front];
    }

    bool isempty(){
        if(front==-1 || front>rear){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;

    cout<<q.isempty()<<endl;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    cout<<"This is the peek value: "<<q.peek()<<endl;

    q.dequeue();
    q.dequeue();
    cout<<"This is the peek value: "<<q.peek()<<endl;

    cout<<q.isempty()<<endl;

    return 0;
}
