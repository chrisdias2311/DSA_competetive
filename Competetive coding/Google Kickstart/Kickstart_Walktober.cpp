#include<iostream>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    int counter=1;
    
    while(tc!=0){
        int participants, days, id, diff=0;
        cin>>participants>>days>>id;
        int arr[participants][days];
        
        for(int i=0; i<participants; i++){
            for(int j=0; j<days; j++){
                cin>>arr[i][j];
            }
        }
        
        for(int i=0; i<days; i++){
            int max = 0;
            for(int j=0; j<participants; j++){
                // arr[j][i];
                if(max<arr[j][i]){
                    max=arr[j][i];
                }
            }

            
            if(arr[id-1][i] < max){
                diff+=max-arr[id-1][i];
            }
        }
        
        cout<<"Case #"<<counter<<": "<<diff<<endl;
        counter++;
        tc--;
    }
    
    return 0;
}