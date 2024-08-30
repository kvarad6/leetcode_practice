//-------- Recursion | Approach 1 | TLE ---------//
class Solution {
public:
    int length = 0;
    void helper(string text1, string text2, int i, int j){
        if(i==text1.length() || j==text2.length()){
            return;
        }
        if(text1[i]==text2[j]){
            length++;
            helper(text1, text2, i+1, j+1);
        }else{
            //saving the current length
            int currentLength = length;

            //moving in text2 using the helper function, store the length
            helper(text1, text2, i, j+1);
            int length1 = length;

            //restoring the length, moving in text1, storing the length
            length = currentLength;
            helper(text1, text2, i+1, j);
            int length2 = length;

            length = max(length1, length2);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        helper(text1, text2, 0, 0);
        return length;
    }
};


//-------- Recursion | Approach 2 | TLE ---------//
class Solution {
public:
    int length = 0;
    void helper(string text1, string text2, int i, int j, int currentLength){
        length = max(length, currentLength);

        if(i==text1.length() || j==text2.length()){
            return;
        }
        if(text1[i]==text2[j]){
            helper(text1, text2, i+1, j+1, currentLength+1);
        }else{
            helper(text1, text2, i, j+1, currentLength);
            helper(text1, text2, i+1, j, currentLength);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int currentLength = 0;
        helper(text1, text2, 0, 0, currentLength);
        return length;
    }
};



//---------- Recursion | Approach 3 | TLE ----------//
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
