//Recursion
class Solution {
    int solve(string &text1, string &text2, int i, int j){
        //base cases
        if(i==text1.length() || j==text2.length()){
            return 0;
        }
        
        //recursive relation
        int ans = 0;
        if(text1[i]==text2[j]){
            ans = 1 + solve(text1, text2, i+1, j+1);
        }
        else{
            ans = max(solve(text1, text2, i, j+1), solve(text1, text2, i+1, j));
        }
        return ans;
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0, 0);
    }
};


// Using DP | Recursion + Memoisation 
// 2D DP: As two variables are getting changed

class Solution {
    int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        //base cases
        if(i==text1.length() || j==text2.length()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //recursive relation
        int ans = 0;
        if(text1[i]==text2[j]){
            ans = 1 + solve(text1, text2, i+1, j+1, dp);
        }
        else{
            ans = max(solve(text1, text2, i, j+1, dp), solve(text1, text2, i+1, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(), vector<int>(text2.length(), -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
