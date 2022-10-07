//String "abcbdecf"
//Find the maximum occuring character 
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    //creation
    map<string,int> m;



    //insertion 
    //1
    pair<string, int> p = make_pair("mango", 3);
    m.insert(p);

    //2
    pair<string,int> pair2("student", 2);
    m.insert(pair2);

    //3
    m["mera"] = 1;

    //What will happen?  4
    m["mera"] = 2;       //Second entry ke liye woh update karega. Khali single entries hoti hai, duplicate entries nahi hoti hai 




    //Searching 
    cout<<m["mango"]<<endl;
    cout<<m.at("student")<<endl;

    // cout<<m.at("unknownkey")<<endl;        // will show that there is no entry and return kar jayega 
    cout<<m["unknownkey"]<<endl;          // will create a new entry and initialize its value with 0

    //check size
    cout<<m.size()<<endl;

    //to check presence 
    cout<<m.count("bro")<<endl;        //will return 0 if the key is absent and 1 if the key is present 

    //erase
    m.erase("love");
    cout<<m.size()<<endl;

    //using for each loop i.e. auto iterator
    // for(auto i:m){           
    //     cout<<i.first<<" "<<i.second<<endl;
    // }


    //using iterator 
    map<string, int> :: iterator  it = m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }


    return 0;
}




std::map<char, int>::iterator it = m.find('c'); 
if (it != m.end())
    it->second = 42;