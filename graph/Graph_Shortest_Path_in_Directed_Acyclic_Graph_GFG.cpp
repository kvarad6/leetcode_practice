class Solution {

  public:
     void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &st){
         visited[node] = 1;
         for(auto it: adj[node]){
             int v = it.first;
             if(!visited[v]){
                 topoSort(v, adj, visited, st);
             }
         }
         st.push(node);
     }
  
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       //create adj list using the edges array given
       //each index represent a node (u) pointing to the pair of integers (v, weight)
       vector<pair<int, int>> adj[N];
       
       for(int i=0;i<M;i++){
           int u = edges[i][0];
           int v = edges[i][1];
           int wt = edges[i][2];
           adj[u].push_back({v,wt});
       }
       
       vector<int> visited(N, 0);
       stack<int> st;
       
       //cover all the components | call dfs function
       for(int i=0;i<N;i++){
           if(!visited[i]){
               topoSort(i, adj, visited, st);
           }
       }
       
       //build the distance array using the topological sorted nodes present in the stack
       vector<int> distanceArray(N, 1e9);  // Using 1e9 instead of INT_MAX to avoid overflow
       distanceArray[0] = 0;
       
       while(!st.empty()){
           int node = st.top();
           st.pop();
           //check curresponding adj elements and the weight in the adj list
           if(distanceArray[node] != 1e9){
           for(auto it: adj[node]){
               int v = it.first;
               int wt = it.second;
               //check if current distance of v from node is lesser thn existing distance mentioned in the distance array
               if(distanceArray[node]+wt < distanceArray[v]){
                   distanceArray[v] = distanceArray[node]+wt;
               }
           }
           }
       }
       
       // Replace 1e9 with -1 for unreachable nodes
       for(int i=0; i<N; i++){
           if(distanceArray[i] == 1e9)
               distanceArray[i] = -1;
       }
       return distanceArray;
    }
};
