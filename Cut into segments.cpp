//Recursion
#include <limits.h>

int solve(int n, int x, int y, int z){
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	//returns max no. of segment for n-x rod + 1 (for 'x' segment) 
	int a = solve(n-x, x, y, z) + 1;

	//returns max no. of segment for n-y rod + 1 (for 'y' segment)
	int b = solve(n-y, x, y, z) + 1;

	//returns max no. of segment for n-z rod + 1 (for 'z' segment)
	int c = solve(n-z, x, y, z) + 1;
	int ans = max(a, max(b,c));
	return ans;
}

int cutSegments(int n, int x, int y, int z) {
	int ans = solve(n, x, y, z);
	if(ans<0){
		return 0;
	}
	else{
		return ans;
	}
	return ans;
}


// Using DP | Top-Down Approach | Recursion + Memoisation
// TC: O(N) | SC: O(N) + O(N)

int solve(int n, int x, int y, int z, vector<int> &dp){
	//base cases
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}

	if(dp[n]!=-1){
		return dp[n];
	}

	//returns max no. of segment for n-x rod + 1 (for 'x' segment) 
	int a = solve(n-x, x, y, z, dp) + 1;

	//returns max no. of segment for n-y rod + 1 (for 'y' segment)
	int b = solve(n-y, x, y, z, dp) + 1;

	//returns max no. of segment for n-z rod + 1 (for 'z' segment)
	int c = solve(n-z, x, y, z, dp) + 1;
	dp[n] = max(a, max(b,c));
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	int ans = solve(n, x, y, z, dp);
	if(ans<0){
		return 0;
	}
	else{
		return ans;
	}
	return ans;
}

// Using DP | Bottom Up Appraoch | Tabulation
// TC: O(N) | SC: O(N)
int solve(int n, int x, int y, int z, vector<int> &dp){
	//base cases
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		if(i-x>=0) dp[i] = max(dp[i], dp[i-x] + 1);
		if(i-y>=0) dp[i] = max(dp[i], dp[i-y] + 1);
		if(i-z>=0) dp[i] = max(dp[i], dp[i-z] + 1);
	}	
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, INT_MIN);
	int ans = solve(n, x, y, z, dp);
	if(ans<0){
		return 0;
	}
	return ans;
	
}

