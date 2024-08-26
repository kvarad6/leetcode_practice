//------ Recursion | Approach 1 --------//
// Using two arrays 
class Solution {
    int solve(vector<int>& nums, int n){
        //base cases
        if(n<0){
            return 0;
        }
        int incl = solve(nums, n-2) + nums[n];
        int excl = solve(nums, n-1) + 0;
        int ans = max(incl, excl);
        return ans;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        if(n==1){
            return nums[0];
        }
        //fill the nums element (from 1st index to the second last index into both the arrays)
        for(int i=0;i<n;i++){
            //add the current element in arr1, if it's not the last element
            if(i!=n-1){
                arr1.push_back(nums[i]);
            }
            //add current element in the arr2, if it's not the first element
            if(i!=0){
                arr2.push_back(nums[i]);
            }
        }
        int ans = max(solve(arr1, n-2), solve(arr2, n-2));
        return ans;
    }
};

//--------- Recursion | Approach 2 ---------//
//Using two arrays, but the initialisation step is modifies
class Solution {
public:
    int helper(int n, vector<int> &nums){
       //base case | to stop the recursion
       if(n<0){
        return 0;
       }
       int include = helper(n-2, nums) + nums[n];
       int exclude = helper(n-1, nums) + 0;
       int ans = max(include, exclude);
       return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> arr1(nums.begin(), nums.end() - 1);
        vector<int> arr2(nums.begin() + 1, nums.end());

        int ans = max(helper(arr1.size()-1, arr1), helper(arr2.size()-1, arr2));
        return ans;
    }
};


//---------- Recursion | Approach 3 ----------//
//Without using two arrays





//------------//

// Using DP | Top-Down Approach | Recursion + Memoisation

class Solution {
    int solve(vector<int>& nums, int n, vector<int>& dp){
        //base cases
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int incl = solve(nums, n-2, dp) + nums[n];
        int excl = solve(nums, n-1, dp) + 0;
        dp[n] = max(incl, excl);
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> first, second;
        vector<int> dp1(n-1, -1), dp2(n-1, -1);
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                second.push_back(nums[i]);
            }
        }
        int ans = max(solve(first, n-2, dp1), solve(second, n-2, dp2));
        return ans;
    }
};

// Using DP | Bottom-Up Approach | Tabulation
class Solution {
    int solve(vector<int>& nums, int n, vector<int>& dp){
        //base cases
        dp[0] = nums[0];
        for(int i=1;i<n-1;i++){
            int incl = nums[i];
            if(i>1) incl += dp[i-2];
            int excl = dp[i-1] + 0;
            dp[i] = max(incl, excl);
        }
        return dp[n-2];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> first, second;
        vector<int> dp1(n-1), dp2(n-1);
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                second.push_back(nums[i]);
            }
        }
        int ans = max(solve(first, n, dp1), solve(second, n, dp2));
        return ans;
    }
};


//Space Optimization 
class Solution {
    int solve(vector<int>& nums, int n){
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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> first, second;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                second.push_back(nums[i]);
            }
        }
        int ans = max(solve(first, first.size()), solve(second, second.size()));
        return ans;
    }
};
