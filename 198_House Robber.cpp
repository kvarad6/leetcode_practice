//Recursion 

class Solution {
public:
    int solve(vector<int>& nums, int n){
        //base cases
        if(n<0){
            return 0;
        }
        if(n==0){
            return nums[0];
        }
        int incl = solve(nums, n-2) + nums[n];
        int excl = solve(nums, n-1) + 0;
        int ans = max(incl, excl);
        return ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(nums, n-1);
        return ans;
    }
};

//Using DP | Top-Down Approach | Recursion + Memoisation 
//TC: O(N) | SC: O(N) for recursion + O(N) for dp array

class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp){
        //base cases
        if(n<0){
            return 0;
        }
        if(n==0){
            return nums[0];
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        int incl = solve(nums, n-2, dp) + nums[n];
        int excl = solve(nums, n-1, dp) + 0;
        dp[n] = max(incl, excl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solve(nums, n-1, dp);
        return ans;
    }
};

// Using DP | Bottom-Up Approach | Tabulation
// TC: O(N)| SC:O(N) 

class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp){
        //base cases
        dp[0] = nums[0];

        for(int i=1;i<n;i++){
            //in case, if index is negative
            int incl = nums[i];
            //for all the positive indexes
            if(i>1) incl += dp[i-2];
            int excl = dp[i-1] + 0;
            dp[i] = max(incl, excl);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int ans = solve(nums, n, dp);
        return ans;
    }
};

// Using Space Optimization
// TC: O(N) | SC: O(1)

class Solution {
public:
    int solve(vector<int>& nums, int n){
        //base cases
        int prev1= nums[0];
        int prev2, curr = 0;

        for(int i=1;i<n;i++){
            //in case, if index is negative
            int incl = nums[i];
            //for all the positive indexes
            if(i>1) incl += prev2;
            int excl = prev1 + 0;
            curr = max(incl, excl);
            prev2 = prev1;
            prev1 = curr; 
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(nums, n);
        return ans;
    }
};
