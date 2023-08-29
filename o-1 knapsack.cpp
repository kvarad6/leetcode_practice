//Using Recursion
int solve(int *weights, int *values, int index, int capacity){
	//base case
	if(index==0){
		//if there is capacity/ empty space in the bag to hold items
		//if only one item to steal, then just comapers its weight with the knapsack capacity
		if(weights[0]<=capacity){
			return values[0];
		}
		//if bag is full/ capacity is reached
		else{
			return 0;
		}
	}
	//include
	int include = 0;
	if(weights[index]<=capacity){
		include = values[index] + solve(weights, values, index-1, capacity-weights[index]);
	}

	//exclude
	int exclude = 0 + solve(weights, values, index-1, capacity);

	int ans = max(include, exclude);
	return ans;
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	return solve(weights, values, n-1, maxWeight);
}

#include <iostream>
#include <vector>
//Using DP | Top Down Approach | Recursion + Memoisation

int solve(int *weights, int *values, int index, int capacity, vector<vector<int>> &dp){
	//base case
	if(index==0){
		if(weights[0]<=capacity){
			return values[0];
		}
		else{
			return 0;
		}
	}
	if(dp[index][capacity]!=-1){
		return dp[index][capacity];
	}
	//include
	int include = 0;
	if(weights[index]<=capacity){
		include = values[index] + solve(weights, values, index-1, capacity-weights[index], dp);
	}

	//exclude
	int exclude = 0 + solve(weights, values, index-1, capacity, dp);

	dp[index][capacity] = max(include, exclude);
	return dp[index][capacity];
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{	
	vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
	return solve(weights, values, n-1, maxWeight, dp);
}

// Using DP | Bottom Up | Tabulation



int knapsack(int *weights, int *values, int n, int capacity)
{	
	vector<vector<int>>dp(n, vector<int>(capacity+1, 0));
	//base case
	for(int w=weights[0];w<capacity;w++){
		if(weights[0]<=capacity){
				dp[0][w] = values[0];
			}
		else{
			dp[0][w]=0;
		}
	}

	//rows: n (0 to n-1)
	//0th case has been already handled above, so index will start from 1 in for loop
	//columns: maxWeight + 1 (0 to maxWeight (here, capacity))
	
	for(int index=1;index<n;index++){
		for(int w=0;w<=capacity;w++){
			//include
			int include = 0;
            if (weights[index] <= w) {
            include = values[index] + dp[index - 1][w - weights[index]];
             }

    		// exclude
            int exclude = 0 + dp[index - 1][w];
			dp[index][w] = max(include, exclude);
        }
	}
	return dp[n-1][capacity];


	
}
