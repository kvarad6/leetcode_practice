// Using Recursion | TLE 
class Solution {
    int solve(vector<int>& nums, int n, int curr, int prev){
        //base case
        if(curr == n){
            return 0;
        }
        //include with condition
        int include = 0;
        if(prev == -1 || nums[curr]>nums[prev]){
            include = 1 + solve(nums, n, curr+1, curr);
        }
        
        //exclude
        int exclude = 0 + solve(nums, n, curr+1, prev);

        return max(include, exclude);

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n, 0, -1);
    }
};

// Using DP | top-down | recursion + memoisation
// here, two states are getting changed (curr, prev), 
// so, need to apply 2d DP.
class Solution {
    int solve(vector<int>& nums, int n, int curr, int prev, vector<vector<int>> &dp){
        //base case
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        //include with condition
        int include = 0;
        if(prev == -1 || nums[curr]>nums[prev]){
            include = 1 + solve(nums, n, curr+1, curr, dp);
        }
        
        //exclude
        int exclude = 0 + solve(nums, n, curr+1, prev, dp);

        dp[curr][prev+1] = max(include, exclude);
        // to avoid invalid index (-1), add 1 to prev index
        return dp[curr][prev+1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(nums, n, 0, -1, dp);
    }
};

