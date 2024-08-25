class Solution {
public:
//------------- Appraoch 1 --------------------//

//Simple recursive sol | Time limit exceeded
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n==0 || n==1) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
    }

//---------------- Approach 2 ---------------------//
// TC: O(N)
// SC: O(N) recursion stack space + O(N) for dp array
//Using DP | Top Down Approach (Recursion + Memoisation)

    int helper(vector<int> &dp, int n){
        //base cond.
        if(n<0){
            return 0;
        }
        if(n==0 || n ==1){
            return 1;
        }
    // checking if result exists in memo, if yes, returned stored value.
        if(dp[n]!=-1){
            return dp[n];
        }
    // compute the result recursively and store it in the memo for future reference.
        dp[n] = helper(dp, n-1) + helper(dp, n-2);
        return dp[n];
    }
    int climbStairs(int n){
        vector<int> dp(n+1, -1);
        return helper(dp, n);
    }


//----------------- Approach 3 ---------------------//
// TC: O(N)
// SC: O(N)
//Using DP | Bottom Up Approach (Tabulation)

    int climbStairs(int n){
        //Creating dp table of size n+1
        vector<int> dp(n+1);
        
         if(n<0){
            return 0;
        }
        if(n==0 || n ==1){
            return 1;
        }
        //base cases
        dp[0]=1;
        dp[1]=1;
        //filling in the DP table by summing up the values for the previous two steps.
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
    //Returns the value in the last cell of the DP table, which represents the total number of ways to reach the top.
        return dp[n];
    }


//-------------------- Approach 4 -------------------//
// TC: O(N)
// SC: O(1)
//Space Optimization

    int climbStairs(int n){
        if(n==0 || n ==1){
            return 1;
        }
        //Using only two variables (prev and curr) instead of an entire DP table
        //initializing them to 1 since there is only one way to reach the base case
        int prev=1, curr=1;
        //for each iteration, updating prev and curr value by shifting their value
        //curr becomes the sum of the previous two values
        for(int i=2;i<=n;i++)
        {
            int temp = curr;
            curr = curr + prev;
            prev = temp;
        }
        return curr;
    }

    //Another solution for space optimization method:

    int climbStairs(int n) {
            if(n<0){
                return 0;
            }
            if(n==0 || n ==1){
                return 1;
            }
            int prev = 1;
            int prev2 = 1;
    
            for(int i=2;i<=n;i++){
                int current = prev + prev2;
                prev2 = prev;
                prev = current;
            }
        return prev;
        }
 
};
