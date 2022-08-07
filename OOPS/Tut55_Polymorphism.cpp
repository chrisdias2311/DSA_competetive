#include<iostream>
using namespace std;

//Function Overloading
//=>Function overloading a feature of object-oriented programming where two or more functions can have the same name but different parameters

// class ApnaCollege{
//     public:
//     void fun(){
//         cout<<"I'm a fuction with no arguments"<<endl;
//     }

//     void fun(int x){
//         cout<<"I'm a function with int arguments"<<endl;
//     }

//     void fun(double x){
//         cout<<"I'm a function with double argument"<<endl;
//     }
// };

// int main(){

//     ApnaCollege obj;
//     obj.fun();
//     obj.fun(4);
//     obj.fun(6.2);

//     return 0;
// }







//Operator overloading 
// class Complex{
//     private:
//     int real, imag;

//     public:
//     Complex(int r=0, int i=0){
//         real = r;
//         imag = i;
//     }

//     //Operator overloading 
//     Complex operator + (Complex const &obj){
//         Complex result;
//         result.imag = imag + obj.imag;
//         result.real = real + obj.real;

//         return result;
//     }

//     void display(){
//         cout<<result<<"+ i"<<imag<<endl;
//     }
// };

// int main(){
//     Complex c1(12, 7), c2(6,7);
//     Complex c3 = c1+c2;

//     c3.display();

//     return 0;
// }








//Function Overriding 

class base{
    public:
    virtual void print(){
        cout<<"This is the base Class's print function"<<endl;
    }

    void display(){
        cout<<"This is the base Class's display function"<<endl;
    }
};

class derived: public base{
    public:
    void print(){
        cout<<"This is the derived Class's print function"<<endl;
    }

    void display(){
        cout<<"This is the base Class's display function"<<endl;
    }
};

int main(){
    base *baseptr;
    derived der;
    baseptr = &der;

    baseptr -> print();

    baseptr -> display();

    return 0;
}