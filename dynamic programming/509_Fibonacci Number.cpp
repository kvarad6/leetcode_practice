class Solution {
    
    //Top Down Approach (Recursion + Memoisation)
    int fibCalculate(int n, vector<int> &dp){
        if(n<=1){
            return n;
        }
        //Check if calculated value is already present in array (memoisation)
        if(dp[n]!=-1){
            return dp[n];
        }
        //recursion
        dp[n] = fibCalculate(n-1, dp) + fibCalculate(n-2, dp);
        return dp[n];
    
public:
    int fib(int n) {
        int answer;
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++){
            dp[i]=-1;
        }
        answer = fibCalculate(n, dp);
        return answer;
    }

    //Bottom Up Approach (Tabulation)
        int fib(int n){
            vector<int> dp(n+1, -1);
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
    
    //Space optimization
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
