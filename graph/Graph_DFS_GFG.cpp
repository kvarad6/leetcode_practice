class Solutions{
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int visited[], vector<int>& ans, int node, vector<int> adj[]){
        visited[node] = 1;
        ans.push_back(node);
        //transverse all its neighbours
        for(auto it: adj[node]){
            if(!visited[it]){
                 dfs(visited, ans, it, adj);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        int start = 0;
        vector<int> ans;
        dfs(visited, ans, start, adj);
        return ans;
        
    }
};
