class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        //The choice of 1e8 instead of 1e9 is primarily to avoid potential integer overflow.
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        //If there are no negative cycles, all shortest paths will be found after at most V-1 iterations.
        for(int i=0; i<V-1; i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Check for negative weight cycle
        for(int i=0; i<V-1; i++){
            bool updated = false;
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    updated = true;
                }
            }
            if(!updated) break;
        }
        
        // Final check for negative cycle
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                return vector<int>(1, -1);  // Negative cycle detected
            }
        }
        
        return dist;
    }
};
