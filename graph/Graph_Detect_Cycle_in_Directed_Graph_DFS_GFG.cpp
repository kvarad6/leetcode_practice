class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node, vector<int> &visited, vector<int> &pathVisited, vector<int> adj[]){
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto adjElement: adj[node]){
            if(!visited[adjElement]){
                if(dfs(adjElement, visited, pathVisited, adj)==true){
                    return true;
                }
            }
            else if(visited[adjElement]==1 && pathVisited[adjElement]==1){
                return true;
            }
        }
        //whenver we are going back, mark pathvisited of the corresponding node as 0
        pathVisited[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i, visited, pathVisited, adj)==true){
                    return true;
                }
            }
        }
        return false;
    }
};
