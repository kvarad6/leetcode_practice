// Recursion
class Solution {
    int solve(int n){
        //base conditions
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        int ans = solve(n-1) + solve(n-2) + solve(n-3);
        return ans;
    }
public:
    int tribonacci(int n) {
        int ans = solve(n);
        return ans;
    }
};

// Using DP | Top-Down Approach | Recursion + Memoisation

class Solution {
    int solve(int n, vector<int> &dp){
        //base conditions
        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = solve(n-1, dp) + solve(n-2, dp) + solve(n-3, dp);
        return dp[n];
    }
public:
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        int ans = solve(n, dp);
        return ans;
    }
};

//Using DP | Bottom-Up Approach | Tabulation

class Solution {
    int solve(int n, vector<int> &dp){
        //base conditions
        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
public:
    int tribonacci(int n) {
        vector<int> dp(n+1);
        int ans = solve(n, dp);
        return ans;
    }
};

// Using Space Optimization 

class Solution {
    int solve(int n){
        //base conditions
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        
        int prev1 = 0;
        int prev2 = 1; 
        int prev3 = 1;
        for(int i=3;i<=n;i++){
            int curr = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = curr;
        }
        return prev3;
    }
public:
    int tribonacci(int n) {
        int ans = solve(n);
        return ans;
    }
};
