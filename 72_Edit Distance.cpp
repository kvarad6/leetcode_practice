// Using Recursion | TLE
class Solution {
    int solve(string &word1, string &word2, int i, int j){
        //base cases
        //if word1 is smaller than word2
        if(i==word1.length()){
            return word2.length() - j;
        }
        //if word2 is smaller than word1
        if(j==word2.length()){
            return word1.length() - i;
        }

        //recursive relations
        //if the characters matches
        int ans = 0;
        if(word1[i]==word2[j]){
            return solve(word1, word2, i+1, j+1);
        }
        else{
            //insert
            int insertAns = 1 + solve(word1, word2, i, j+1);
            //delete
            int deleteAns = 1 + solve(word1, word2, i+1, j);
            //replace
            int replaceAns = 1 + solve(word1, word2, i+1, j+1);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        dp[i][j] = ans;
        return dp[i][j];

    }
public:
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
};

// Using DP | Top Down | Recursion + Memo
class Solution {
    int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        //base cases
        //if word1 is smaller than word2
        if(i==word1.length()){
            return word2.length() - j;
        }
        //if word2 is smaller than word1
        if(j==word2.length()){
            return word1.length() - i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //recursive relations
        //if the characters matches
        int ans = 0;
        if(word1[i]==word2[j]){
            return solve(word1, word2, i+1, j+1, dp);
        }
        else{
            //insert
            int insertAns = 1 + solve(word1, word2, i, j+1, dp);
            //delete
            int deleteAns = 1 + solve(word1, word2, i+1, j, dp);
            //replace
            int replaceAns = 1 + solve(word1, word2, i+1, j+1, dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        dp[i][j] = ans;
        return dp[i][j];

    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
