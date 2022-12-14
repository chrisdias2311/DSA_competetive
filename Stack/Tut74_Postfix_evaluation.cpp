#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int postfixEvaluation(string s){
    stack<int> st;
    int op2, op1;

    for(int i=0; i<s.length(); i++){
        if (s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        } else {
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
    
            case '-':
                st.push(op1-op2);
                break;

            case '*':
                st.push(op1*op2);
                break;

            case '/':
                st.push(op1/op2);
                break; 

            case '^':
                st.push(pow(op1,op2));
                break;               
        
            default:
                break;
            }
        }
    }
    return st.top();
}

int main(){
    cout<<postfixEvaluation("A-(B/C+(d'E*F)/G)*H");

    return 0;
}


//Time complexity O(l) where l is the length of the string 