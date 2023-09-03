#include<unordered_map>
#include<list>
#include<queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	//Prepare adj list
	unordered_map<int, list<int>> adj;
	for(int i=0;i<m;i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// prepare visited unordered map
	unordered_map<int, bool> visited;

	//prepare datastructure to store parent nodes
	unordered_map<int, int> parents;

    queue<int> q;
	visited[s] = true;
	q.push(s);
	parents[s] = -1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(int i: adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parents[i] = front;
				q.push(i);
			}
		}
	}
	//prepare shortest path | backtracking from destination node to source node
	vector<int> ans;
	int currentNode = t;
	ans.push_back(currentNode);

	while(currentNode != s){
		currentNode = parents[currentNode];
		ans.push_back(currentNode);
	}

	//reverse the resultant array to get path from source node to destination node
	reverse(ans.begin(), ans.end());
	return ans;


	
}
