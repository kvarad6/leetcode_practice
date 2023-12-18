// Using Recursion | TLE
class Solution {
    int solve(vector<int>& nums, int n, int target){
        //base case
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        int ans = 0;
        //recursive relation
        for(int i=0;i<n;i++){
            ans += solve(nums, n, target-nums[i]);
        }
        return ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, n, target);
    }
};

// Using DP | Top Down Approach | Recursion + Memoisation
class Solution {
    int solve(vector<int>& nums, int n, int target, vector<int>& dp){
        //base case
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }

        if(dp[target]!=-1){
            return dp[target];
        }
        int ans = 0;
        //recursive relation
        for(int i=0;i<n;i++){
            ans += solve(nums, n, target-nums[i], dp);
        }
        dp[target] = ans;
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        //sub problmes are getting generated based on target, so, taking dp array of size target + 1, as range goes from 0 to target.
        vector<int> dp(target+1, -1);
        return solve(nums, n, target, dp);
    }
};

// Using DP | Bottom Up Approach | Tabulation

class Solution {
    int solve(vector<int>& nums, int n, int target, vector<unsigned int>& dp){
        //base case
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        dp[0] = 1;
        //traversing from target: 1 to target
        for(int i=1;i<=target;i++){
            //traversing on nums vector
            for(int j=0;j<n;j++){
                if(i-nums[j]>=0){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        //sub problmes are getting generated based on target, so, taking dp array of size target + 1, as range goes from 0 to target.
        vector<unsigned int> dp(target+1, 0);
        return solve(nums, n, target, dp);
    }
};
