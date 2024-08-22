class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        //format in which priority queue stores: pair<distance, node>
        pq.push({0, S});
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto adjElement : adj[node]){
                int edgeWeight = adjElement[1];
                int adjNode = adjElement[0];
                
                if(edgeWeight + distance < dist[adjNode]){
                    dist[adjNode] = edgeWeight + distance;
                    pq.push({dist[adjNode], adjNode});
            }
        }
        
    }
    return dist;
    }
};
