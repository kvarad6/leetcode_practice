class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //initialise the adj list u-> {prob, v}
        vector<pair<int, double>> adj[n];

        //fill the adj list with the help of edges and succProb array
        //edges structure: [[0,1],[1,2],[0,2]] | edges[i][0] -> u & edges[i][1] -> v
        //and as it is undirected, there should be u->v and v->u
        //so, the str of adj list can be: u -> {v, wt}
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        //initialise an priority queue (max-heap | less is not required, as it would be max heap by default)
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        //initialise an distance array, to store the max distance/ weights (here, probabilities) to reach each node from the start node
        vector<double> distArray(n, INT_MIN);
        distArray[start_node] = 1.0; 

        //transverse the priority queue
        while(!pq.empty()){
            double dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto adjElement: adj[node]){
                int adjNode = adjElement.first;
                double edgeWt = adjElement.second;
                //going greedy
                if(distArray[adjNode]<edgeWt*dist){
                    distArray[adjNode] = edgeWt*dist;
                    //push the updated distance and adjnode in the queue
                    pq.push({distArray[adjNode], adjNode});
                }
            }
        }
        if(distArray[end_node]==INT_MIN){
            return 0.0;
        }
        else{
            return distArray[end_node];
        }

    }
};
