#include <list>
#include <vector>
#include <unordered_map>
#include <queue>

bool bfs(int sourceNode, unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited){
    //datastructure to store parent node
    unordered_map<int, int> parent;
    //parent of source node -> -1
    parent[sourceNode] = -1;

    //mark source node as visited
    visited[sourceNode] = 1;

    queue<int> q;
    q.push(sourceNode);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

    //to check for neighbour and condition for cyclic graph
    for(auto neighbour: adj[frontNode]){
        if(visited[neighbour] && neighbour != parent[frontNode]){
            return true;
        }
        else if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour] = 1;
            parent[neighbour] = frontNode;
        }
    }
    
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //Prepare Adj List
    unordered_map<int, list<int>> adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //bfs for each component
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
         bool ans = bfs(i, adj, visited);   
         if(ans == 1){
             return "Yes";
         }
        }
    }
    return "No";
}




