#include<iostream>
using namespace std;

void main(){
    int a=10;  //Stored in stack

    int *p = new int();  //Pointer P is created which point towards an empty space which is created in Heap (by new int())

    *p = 10; //p is a pointer which is stored in stack, and p is pointing towards a memory address in heap. and here we have stored 10 in  the memory address 

    delete(p); // used to deallocate memory 
    // But the pointer p is still pointing towards the memory location, such a pointer is known as a dangling pointer 

    p = new int[4];  // Reuse the pointer (Here p will point towards the 0th element of the array and will store the ML of the 0th elemet of the array)

    delete[] p;   // deallocate the memory which is allocated for the array 

    p = NULL;

    //If we dont delete or reuse the dangling pointer, it results in memory leak, which is a serious issue while working on servers
}