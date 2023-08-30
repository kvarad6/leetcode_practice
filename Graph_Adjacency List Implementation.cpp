// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph{
    public:
    //Declared unordered map
    //key: int object | individual vertex
    //value: list of objects | collection of vertices connected with its keys
    unordered_map<int, list<int>>adj;
    
    
    void edge(int u, int v, int direction){
        // direction == 0 -> Undirected graph
        // direction == 1 -> Directed graph
        
        // creating edge from u to v | single direction
        adj[u].push_back(v);
        //for undirected graph, v to u is also possible
        if(direction == 0){
            adj[v].push_back(u);
        }
    }
    
    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<"-->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
   int n;
   cout<<"Enter no. of Nodes:";
   cin>>n;
   
   int m;
   cout<<"Enter no. of Edges:";
   cin>>m;
   
   graph g;
   
   for(int i=0;i<m;i++){
       int u, v;
       cin>>u>>v;
       g.edge(u, v, 0);
   }
   g.printAdjList();
}
