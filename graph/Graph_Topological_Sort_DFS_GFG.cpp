class Solution
{

	public:
	
	void dfs(int node, stack<int> &st, vector<int> &visited, vector<int> adj[]){
        visited[node] = 1;
        
        for(auto adjElement: adj[node]){
            if(!visited[adjElement]){
                dfs(adjElement, st, visited, adj);
            }
        }
        //before returning, push the node to stack
        st.push(node);
    }
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V, 0);
	    stack<int> st;
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i, st, visited, adj);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
