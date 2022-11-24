#include<iostream>
using namespace std;

// int main(){
//     int tc;
//     cin>>tc;
//     int num=1;
    
//     while(tc!=0){
//         int len, noOfRuns, laps=0, distance, prevDistance;
//         cin>>len>>noOfRuns;
//         char direction='f', prevDirection;
//         for(int i=1; i<=noOfRuns; i++){
//             cin>>distance;
//             prevDirection = direction;
//             cin>>direction;
//             if(prevDirection=='f'){
//                 if(distance>=len){
//                     prevDistance=distance;
//                     while(prevDistance>=len){
//                         laps++;
//                         prevDistance-=len;
//                     }
//                 }else{
//                     prevDistance=distance;
//                 }
//             }else if(prevDirection==direction){
//                 if((prevDistance+distance)>=len){
//                     prevDistance=prevDistance+distance;
//                     while(prevDistance>=len){
//                         laps++;
//                         prevDistance-=len;
//                     }
//                 }else{
//                     prevDistance+=distance;
//                 }
//             }else if(prevDirection!=direction){
//                 if((distance-prevDistance)>=len){
//                     prevDistance=distance-prevDistance;
//                     while(prevDistance>=len){
//                         laps++;
//                         prevDistance-=len;
//                     }
//                 }else{
//                     prevDistance=distance-prevDistance;
//                 }
//             }   
//         }
//         cout<<"Case #"<<num<<": "<<laps<<endl;
//         num++;
//         tc--;
//     }
// }



int main(){
    int tc;
    cin>>tc;
    int num=1;
    
    while(tc!=0){
        int len, runs, laps=0;
        cin>>len>>runs;
        int distance,clockwiseDistance=0, antiClockwiseDistance=0;

        for(int i=1; i<=runs; i++){
            char dir;

            cin>>distance>>dir;

            if(dir=='C'||dir=='c'){
                clockwiseDistance+=distance;
            } else if(dir=='A'||dir=='a'){
                antiClockwiseDistance+=distance;
            }

            if(antiClockwiseDistance>clockwiseDistance){
                antiClockwiseDistance-=clockwiseDistance;
                laps+=antiClockwiseDistance/len;
            }else{
                clockwiseDistance-=antiClockwiseDistance;
                laps+=clockwiseDistance/len;
            }

            cout<<"cd: "<<clockwiseDistance<<endl;
            cout<<"acd: "<<antiClockwiseDistance<<endl;
            cout<<endl;
        }
        
        cout<<"Case #"<<num<<": "<<laps<<endl;
        num++;
        tc--;
    }
}