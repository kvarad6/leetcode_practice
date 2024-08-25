//-------------- Appraoch 1 | Recursion -------------//

class Solution {
public:
    int solve(int n){
        //base cases
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        return solve(n-1) + solve(n-2);
    }

    int fib(int n) {
        return solve(n);
    }
};

//--------------- Appraoch 2 | Recursion + Memoisation | Top-Down Approach -------------//
// Starting answer you reuired -> then go back to base case and come back
// Top-down starts from the original problem and breaks it down into smaller subproblems
// Top-down is a recursive problem-solving approach
// TC: O(N)
// SC: O(N) for recursion stack space + O(N) for DP Array

class Solution {
public:
    int fibCalculate(int n, vector<int> &dp){
        //base cases
        if(n<=1){
            return n;
        }

        //Check if calculated value is already present in array (memoisation)
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n] = fibCalculate(n-1, dp) + fibCalculate(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        int answer;
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++){
            dp[i] = -1;
        }
        //above step can also be written as : vector<int> dp(n+1, -1);
        answer = fibCalculate(n, dp);
        return answer;
    }
};



//-------------- Approach 3 | Tabulation | Bottom-Up Appraoch ---------------//
// From base case to the required answer
// Bottom-up starts from the smallest subproblems and builds up to the original problem
// Bottom-up is an iterative problem-solving approach.
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int fib(int n) {
        int answer;
        vector<int> dp(n+1, -1);
        //base cases

        if(n<=1){
            return n;
        }
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


//-------------- Approach 4 --------------//
// Space optimization
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int fib(int n){
        int prev1 = 1;
        int prev2 = 0;
        int curr;
        if(n<=1){
            return n;
        }

        for(int i=2;i<=n;i++){
            //shifting logic
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
