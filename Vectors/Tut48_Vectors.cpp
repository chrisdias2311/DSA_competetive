#include<iostream>
using namespace std;
#include<vector>

// int main(){

//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);

//     for(int i=0; i<v.size(); i++){
//         cout<<v[i]<<" ";
//     }

//     vector<int>::iterator it;
//     for(it=v.begin() ; it!=v.end() ; it++){
//         cout<<*it<<" ";
//     }

//     for(auto i:v){
//         cout<<i<<" ";
//     }

//     v.pop_back();

//     vector<int> v2 = (3,50);     //(size, element)  v2 = 50 50 50

//     swap(v,v2);


//     sort(b.begin(), v.end());

//     return 0;
// }











#include <iostream>
using namespace std;
#include<vector>

int main() {
	// your code goes here
	int tc;
	cin>>tc;
	
	while(tc != 0){
	    int len, num, plus=0, minus=0;
	    cin>>len;
	    vector<int> newArr;
	    
	    string myStr;
	    cin>>myStr;
	    
	    string ans = "";
	    
	    for(int i=0; i<len; i++){
	        if(myStr[i]!='+' || myStr[i]!='-'){
	            num = myStr[i]-48;
	            newArr.push_back(num);
	        } else if(myStr[i]=='+'){
	            plus++;
	        } else if(myStr[i]=='-'){
	            minus++;
	        }
	    }
	    
	    sort(newArr.begin(), newArr.end(), greater<int>());
	    int counter = len - (minus+plus);
	    
	    int j=0;
	    for(int i=0; i<len; i++){
	        if(counter>0){
	           char ch = newArr[i];
	           ans[j] = ch;
	           j++;
	           counter --;
	        } else if(plus>0){
	            ans[j]= '+';
	            j++;
	            ans[j]=newArr[i];
	        } else if(minus>0){
	            ans[j]='-';
	            j++;
	            ans[j]=newArr[i];
	        } 
	    }
	    
	    cout<<ans<<endl;
	    
	    tc--;
	}
	
	return 0;
}
