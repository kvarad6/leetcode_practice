//Using Recursion | TLE
class Solution {
    int solve(string &s, string &reverseString, int i, int j){
        //base cases
        if(i==s.length() || j==reverseString.length()){
            return 0;
        }
        //recursive relations
        int ans = 0;
        if(s[i]==reverseString[j]){
            ans = 1 + solve(s, reverseString, i+1, j+1);
        }
        else{
            ans = max(solve(s, reverseString, i+1, j), solve(s, reverseString, i, j+1));
        }
        return ans;
    }
public:
    int longestPalindromeSubseq(string s) {
        string reverseString = s;
        reverse(reverseString.begin(), reverseString.end());
        return solve(s, reverseString, 0, 0);
    }
};

//Using DP | Top Down | Recursion + Memoisation
class Solution {
    int solve(string &s, string &reverseString, int i, int j, vector<vector<int>> &dp){
        //base cases
        if(i==s.length() || j==reverseString.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //recursive relations
        int ans = 0;
        if(s[i]==reverseString[j]){
            ans = 1 + solve(s, reverseString, i+1, j+1, dp);
        }
        else{
            ans = max(solve(s, reverseString, i+1, j, dp), solve(s, reverseString, i, j+1, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
public:
    int longestPalindromeSubseq(string s) {
        string reverseString = s;
        reverse(reverseString.begin(), reverseString.end());
        vector<vector<int>>dp(s.length(), vector<int>(reverseString.length(), -1));
        return solve(s, reverseString, 0, 0, dp);
    }
};
