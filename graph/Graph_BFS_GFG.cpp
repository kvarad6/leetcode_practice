//0-based graph: as graph is starting from 0,
//so need to create an adjacency list of size n+1, n-> no. of nodes
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        //declare visited array, initially containing 0's
        int visited[V] = {0};
        
        //marking first node as visited (1)
        visited[0] = 1;
        
        //declaring bfs array to store the nodes level-vise | BFS
        vector<int> bfs;
        
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            //to check corresponding neighbours in the adj list, and if not visited, mark them as visited and add them in queue
            for(auto it: adj[node]){
                if(visited[it]==0){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
        
    }
