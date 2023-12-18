


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    unordered_map<int, bool> visited;
    vector<int> ans;
    queue<int> q;

    q.push(0);

    while(!q.empty()){
        int frontNode = q.front();
        //to check if the current node is visited or not and of not, then push it to queue and mark it as visited
        if(!visited[frontNode]){
            ans.push_back(frontNode);
            visited[frontNode] = true;
        }
        //to add the neighbours in queue if they are already not visited
        for(auto it:adj[frontNode]){
            if(!visited[it]){
                q.push(it);
            }
        }  
        //pop the visited node whose neighbours have been added in queue
        q.pop(); 
    }

    return ans;
}
