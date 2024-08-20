class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool helper(int source, vector<int> adj[], vector<int> &visited){
        
        //marking source node as visited
        visited[source] = 1;
        //declare a queue to store pair of current node and immediate parent
        queue<pair<int, int>>q;
        q.push({source, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            //transverse the adj list, and if the neighbour is not visited, add it in queue
            for(auto adjElement : adj[node]){
                //if the adj node is not already visited, just mark it as visited
                if(visited[adjElement]==0){
                    visited[adjElement]=1;
                    q.push({adjElement, node});
                //else, if adj node is already visited, but it's not the parent, then we can say that cycle present in the graph,
                //as, in the bfs, we always traval equally in both paths, if the adj node is already visited, that means, it's marked as visited by other path, which is connected. 
                }else if(parent!=adjElement){
                    return true;
                }
            }
            
        }
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        //also need to handle if components are broken
        //here, we are covering all the components (connected/ not-connected)
        for(int i=1;i<V;i++){
            //here, we are skipping all the nodes which are visited in a component (skipping the entire component who is one's covered)
            if(!visited[i]){
                if(helper(i, adj, visited)==true){
                    return true;
                }
            }
        }
        return false;
    }
};
