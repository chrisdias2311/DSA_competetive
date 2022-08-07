#include<iostream>
using namespace std;

// class student{
//     string name;       //private

//     public: 
//     int age;
//     bool gender;

//     void setName(string s){          //Setter
//         name = s;
//     }

//     void getName(){
//         cout<<name;
//     }

//     void printInfo(){
//         cout<<"Name = ";
//         cout<<name<<endl;

//         cout<<"Age = ";
//         cout<<age<<endl;

//         cout<<"Gender = ";
//         cout<<gender<<endl;
//     }
// };

// int main(){
//     // student a;
//     // a.name='Urvi';
//     // a.age=20;
//     // a.gender=1;

//     student arr[3];
//     for(int i=0;i<3;i++){
//         string s;
//         cout<<"Name = ";
//         // cin>>arr[i].name;      //When name is public
//         cin>>s;
//         arr[i].setName(s);

//         cout<<"Age = ";
//         cin>>arr[i].age;

//         cout<<"Gender = ";
//         cin>>arr[i].gender;
//     }

//     for(int i=0;i<3;i++){
//         arr[i].printInfo();
//         cout<<endl;
//     }

//     return 0;
// }












//Constructor Destructor
class student{
    string name;
    public: 
    
    int age;
    bool gender;

    void setName(string s){          //Setter
        name = s;
    }
    void getName(){
        cout<<name;
    }

    student(){
        cout<<"\n Default Constructor"<<endl;
    }//Default constructor
    

    student(string n, int a, bool g){
        cout<<"\n Parameterised Constructor";
        name = n;
        age = a;
        gender = g;
    }//Parameterized constructor

    student(student &s1){
        cout<<"\n Copy Constructor";
        name = s1.name;
        age = s1.age;
        gender = s1.gender;
    }//Deep copy constructor

    ~student(){
        cout<<"Destructor Called"<<endl;
    } //Destructor


    void printInfo(){
        cout<<"\n Name = ";
        cout<<name<<endl;

        cout<<"Age = ";
        cout<<age<<endl;

        cout<<"Gender = ";
        cout<<gender<<endl;
    }


    //Operator Overloading
    bool operator == (student &a){
        if(name==a.name && age==a.age && gender==a.gender){
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    student s1("Chris", 18, true);           // instance of "Student" s1 is ccreated
    student s2;          //Will call the default constructor  (Will create an instance of student with garbage values)
    student s3 = s1;     //Shallow(Default) copy constructor

    // s2.printInfo();      //Will print garbage values as default constructor is empty 
    // s3.printInfo();      //Will print the values of s1


    //Operator overloading (Asing an operator to behave in a particular manner)
    if(s3==s1){
        cout<<"\nSame"<<endl;
    } else {
        cout<<"\nNot Same"<<endl;
    }

    return 0;
}