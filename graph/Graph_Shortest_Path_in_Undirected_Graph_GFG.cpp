class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //create an adj list using the edges
        //as the graph is undirected, we need to consider two paths (u->v and v->u)
        vector<int> adj[N];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //initialising the distance array
        vector<int> distanceArray(N, 1e9);
        //for source node, self distance is '0'
        distanceArray[src] = 0;
        
        //initialising the visited array
        vector<int> visited(N, 0);
        
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto adjElement: adj[node]){
                if(distanceArray[node] + 1 < distanceArray[adjElement]){
                    distanceArray[adjElement] = distanceArray[node] + 1;
                    q.push(adjElement);
                } 
            }
        }
        
        //handling unreachable nodes | returning -1 for that node
        //for all the nodes that contains distance as 1e9, stay as -1 in ans, other will be updated as per the distance array
        vector<int> ans(N, -1);
        for(int i=0;i<N;i++){
            if(distanceArray[i]!=1e9){
                ans[i] = distanceArray[i];
            }
        }
        return ans;
        
    }
};
