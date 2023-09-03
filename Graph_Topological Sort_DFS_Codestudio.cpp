#include <bits/stdc++.h> 

void topoDfs(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj){
    visited[node] = 1;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topoDfs(neighbour, visited, s, adj);
        }
    }
    //push node in stack after returning in recursion
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Prepare adj list

    unordered_map<int, list<int>> adj;

    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // dfs for each component
    vector<bool> visited(v);
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoDfs(i, visited, s, adj);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
