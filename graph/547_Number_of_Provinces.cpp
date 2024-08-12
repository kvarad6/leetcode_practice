class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<int> &visited){
        //mark visited node as 1 in visited array
        visited[node] = 1;

        //run a loop over the connected nodes of the 'node', and call dfs for the same
        for(int i=0;i<adjList[node].size();i++){
            int neighbor = adjList[node][i];
            if(!visited[neighbor]){
                dfs(neighbor, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //finding no. of nodes
        int v = isConnected.size();

        //convert given adj matrix to list
        // vector<int> adjList[v];
        vector<vector<int>> adjList(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        //declare visited array
        // int visited[v] = {0};
        vector<int> visited(v, 0);

        //maintain a counter to count no. of dfs/bfs calls
        //the total no. of calls are the no. of provinces
        int count = 0;

        for(int i=0;i<v;i++){
            if(!visited[i]){
                count++;
                dfs(i, adjList, visited);
            }
        }
        return count;
    }
};
