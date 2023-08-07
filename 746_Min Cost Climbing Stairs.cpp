class Solution {
    //Recursive solution | TLE
    int solve(vector<int>& cost, int n){
        //base cases
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //for top step, where cost will not be included
        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;

    }

    //Using DP | Recursion + Memoisation 

    int solve(vector<int>& cost, int n,  vector<int> &dp){
        //base cases
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }

    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            vector<int> dp(n+1, -1);
            //for top step, where cost will not be included
            int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
            return ans;
        }

    //Using DP | Tabulation 

    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            vector<int> dp(n+1);
            dp[0] = cost[0];
            dp[1] = cost[1];
            for(int i=2;i<n;i++){
                dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            }
            return min(dp[n-1], dp[n-2]);
        }

    //Space Optimization 
    public:
       int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            //base cases
            if(n==0){
                return cost[0];
            }
            if(n==1){
                return cost[1];
            }
            int prev  = cost[0];
            int curr = cost[1];
            for(int i=2;i<n;i++){
                int temp = curr;
                curr = cost[i] + min(prev, curr);
                prev = temp;
            }

            return min(prev, curr);
        } 


};
