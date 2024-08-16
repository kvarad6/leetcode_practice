class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, int parent, vector<int> &visited, vector<int> adj[]){
        visited[node] = 1;
        
        for(auto adjElement: adj[node]){
            if(!visited[adjElement]){
                if(dfs(adjElement, node, visited, adj)==true){
                    return true;
                }
            }
            else if(adjElement!=parent){
                return true;
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        //if graph has only a single component, this should work:
        //return dfs(1, -1, visited, adj);
        
        //but the graph can have multiple components:
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i, -1, visited, adj)==true){
                    return true;
                }
            }
        }
        return false;
    }
};
