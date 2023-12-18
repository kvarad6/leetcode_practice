// Recursion
class Solution {
    int solve(int n){
        //base cases
        if(n==0){
            return 0;
        }
        int ans = n;
        //recursive relation
        for(int i=1;i*i<=n;i++){
            int temp = i*i;
            ans = min(ans, 1+solve(n-temp));
        }
        return ans;
    }
public:
    int numSquares(int n) {
        return solve(n);
    }
};

// Recursion + Memo
class Solution {
    int solve(int n, vector<int> &dp){
        //base cases
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = n;
        //recursive relation
        for(int i=1;i*i<=n;i++){
            int temp = i*i;
            ans = min(ans, 1+solve(n-temp, dp));
        }
        dp[n] = ans;
        return dp[n];
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
