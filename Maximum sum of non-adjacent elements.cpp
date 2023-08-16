#include <bits/stdc++.h> 

// //Recursion | TLE
int solve(vector<int> &nums, int n){
    //base cases
    if(n<0){
        return 0;
    }
    //if only one element is present, so return element present at oth index
    if(n==0){
        return nums[0];
    }
    //Including the current element
    int incl = solve(nums, n-2) + nums[n];

    //Excluding the current element
    int excl = solve(nums, n-1);

    return max(incl, excl); 
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //returning array and index of last element
    int ans = solve(nums, n-1);
    return ans;

}

// Using DP | Top-Down Approach | Recursion + Memoisation
// TC: O(N) | SC: O(N) for recursion + O(N) for dp array

int solveMem(vector<int> &nums, int n, vector<int> &dp){
      //base cases
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    //Checking if subproblem already solved and stored
    if(dp[n]!=-1){
        return dp[n];
    }

    //Including the current element
    int incl = solveMem(nums, n-2, dp) + nums[n];

    //Excluding the current element
    int excl = solveMem(nums, n-1, dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}


int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    //returning array and index of last element
    int ans = solveMem(nums, n-1, dp);
    return ans;

}

//DP | Bottom-Up Approach | Tabultion
// TC: O(N) | SC: O(N)

int solveTab(vector<int> &nums, int n, vector<int> &dp){
    //base cases
    dp[0] = nums[0];

    for(int i=1;i<=n;i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }
    
    return dp[n];

}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n);
    //returning array and index of last element
    int ans = solveTab(nums, n-1, dp);
    return ans;
}

// Space Optimization
// TC: O(n) | SC: O(1)

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //using base cases,
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i=1;i<n;i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
