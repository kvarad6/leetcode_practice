class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> indegree(V, 0);
        vector<int> topoSort;
        
        //fill out the indegrees
        for(int i=0;i<V;i++){
            for(auto adjElement: adj[i]){
                indegree[adjElement]++;
            }
        }
        
        //check if any node has indegree 0, if yes, put it into the queue
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        //transverse queue, add node in topo sort, check for adj nodes
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            
            //check for curresponding adj elements
            for(auto adjElement: adj[node]){
                indegree[adjElement]--;
                if(indegree[adjElement]==0){
                    q.push(adjElement);
                }
            }
        }
        
        //after getting final topo sort, check its size, determine if cycle is present
        if(topoSort.size()!=V){
            return true;
        }
        return false;
    }
};
