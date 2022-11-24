#include<iostream>
using namespace std;

//Reverse a string using recursion 
// void reverse(string s){
//     if(s.length()==0){
//         return;
//     }

//     string ros = s.substr(1);
//     reverse(ros);

//     cout<<s[0];
// }

// int main(){

//     reverse("Binod");

//     return 0;
// }








//replace pi with 3.14 in a string 

// void replacePi(string s){
//     if(s.length() == 0){
//         return; 
//     }

//     if(s[0]=='p' && s[1]=='i'){
//         cout<<"3.14";
//         replacePi(s.substr(2));
//     } else {
//         cout<<s[0];
//         replacePi(s.substr(1));
//     }
// }

// int main(){

//     replacePi("pippppiiiipi");

//     return 0;
// }











//Tower of Hanoi

void towerOfHanoi(int n, char src, char dest, char helper){
    if(n==0){
        return;
    }

    towerOfHanoi(n-1, src, helper, dest);               //first move topmost n-1 bloacks from rc to helper 
    cout<<"Move from "<<src<<" to "<<dest<<endl;        //Move the boottommost block from src to dest 
    towerOfHanoi(n-1, helper, dest, src);               // Move the blocks in helper to destination 
}
int main(){
    towerOfHanoi(3, 'A', 'B', 'C');
}










//Remove all the duplicates of a string

// string removeDup(string s){
//     if(s.length()==0){
//         return "";
//     }

//     char ch = s[0];
//     string ans = removeDup(s.substr(1));

//     if(ch==ans[0]){
//         return ans;
//     } else {
//         return (ch+ans);
//     }
// }

// int main(){
//     cout<<removeDup("aaaabbbeeecdddd");

//     return 0;
// }










//Move all X to the end of the string 
// string moveAllX(string s){
//     if(s.length()==0){
//         return "";
//     }

//     char ch=s[0];
//     string ans = moveAllX(s.substr(1));

//     if(ch=='x'){
//         return (ans+ch);
//     } 
//     return ch+ans;
// }
// int main(){
//     cout<<moveAllX("axxbdxcefxhix");
// }









//Print all the substrings of a string          (If length of the string is N then the number of substrings is 2^n)
// void subSequence(string s, string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return;
//     }

//     char ch=s[0];
//     string ros = s.substr(1);

//     subSequence(ros, ans);            
//     subSequence(ros, ans+ch);
// }

// int main(){
//     subSequence("ABC", "");

//     return 0;
// }











//Print all the combinations of a word alonge with its ASCII code 

// void subSequence(string s, string ans){
//     if(s.length()==0){
//        cout<<ans<<endl;
//        return; 
//     }

//     char ch = s[0];
//     int code = ch;
//     string ros = s.substr(1);

//     subSequence(ros, ans);
//     subSequence(ros, ans + ch);
//     subSequence(ros, ans + to_string(code));
// }

// int main(){

//     subSequence("AB", "");

//     return 0;
// }











//Print allthe possible words from phone digits 
// string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// void keypad(string s, string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return; 
//     } 

//     char ch  = s[0];
//     string code = keypadArr[ch-'0'];

//     string ros = s.substr(1);

//     for(int i=0; i<code.length(); i++){
//         keypad(ros, ans + code[i]);
//     }
// }

// int main(){

//     keypad("23", "");

//     return 0;
// }








//JAVA course approach
// string keypadArr[] = {"", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// void printCombinations(string str, int idx, string combination){        //string number, index, ans    
//    if(idx==str.length()){
//        cout<<combination<<endl;
//        return; 
//    }
//    char currChar = str[idx];  
//     string mapping = keypadArr[currChar-'0'];

//     for(int i=0; i<mapping.length(); i++){
//         printCombinations(str, idx+1, combination+mapping[i]);
//     }

// }

// int main(){
//     printCombinations("23", 0, "");

//     return 0;
// }