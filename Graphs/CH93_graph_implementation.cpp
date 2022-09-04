#include<iostream>
#include<unordered_map>
#include<list>
#include<map>
#include<vector>
using namespace std;

//using map<int, list<int>>;
class graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        //direction = 0 -> undirected 
        //directin = 1-> directed graph

        //create an edge from u to v 
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of nodes ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges";
    cin>>m;

    graph g;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        //creating an undirected graph 
        g.addEdge(u,v,0);
    }

    //print the graph 
    g.printAdjList();
    return 0;
}











//using <vector<vector<int>>

// vector<vector<int>>printAdjacency(int n, int m, vector<vector<int>> &edges){
//     vector<int> ans[n];
//     for(int i=0; i<m; i++){
//         int u = edges[i][0];
//         int v = edges[i][1];

//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }
// }