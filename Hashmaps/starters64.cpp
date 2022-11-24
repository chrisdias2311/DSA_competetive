

#include <iostream>
#include<map>
using namespace std;

int main() {
    int tc;
    cin>>tc;
    
    while(tc!=0){
        map<int, int> m;
        int noOfEntries;
        cin>>noOfEntries;
        
        for(int i=0; i<noOfEntries; i++){
            int newEntry;
            cin>>newEntry;
            
            if(m.count(newEntry)){
                m[newEntry]++;
            }else{
                pair<int,int> aPair(newEntry, 0);
                m.insert(aPair);
            }
        }
        
        bool secondFlag=false;
        
        // map<int,int> :: iterator it = m.begin();
        // while(it!=m.end()){
        //     cout<<it->first<<" "<<it->second<<endl;
        //     it++;
        // }
        
        map<int,int> :: iterator it = m.begin();
        while(it!=m.end()){
            if(it->second!=0){
                secondFlag=true;
                break;
            }
        }
        
        if(secondFlag==true){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
        tc--;
    }
    
	return 0;
}
