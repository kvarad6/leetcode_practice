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

