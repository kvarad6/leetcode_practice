
void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &component){
    component.push_back(node);
    visited[node] = true;

    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i, adj, visited, component);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    //prepare adjacency list 
    unordered_map<int, list<int>>adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

  
    //as graph is disconnected, need to cover all components
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    
    for(int i=0;i<V;i++){
        
        if(!visited[i]){
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }
    return ans;

}
