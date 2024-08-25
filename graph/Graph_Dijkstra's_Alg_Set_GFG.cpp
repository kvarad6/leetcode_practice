class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        
        st.insert({0, S});
        dist[S] = 0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int distance = it.first;
            st.erase(it);
            for(auto adjElement : adj[node]){
                int adjNode = adjElement[0];
                int adjWeight = adjElement[1];
                //if we got the lessaer distance, than the one existed in the set, just erase the existed one to insert the updated smaller one
                if(distance + adjWeight < dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = distance + adjWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};