/*
-> At each index, we are considering two options:
    1. Consider it as an extra character
    2. Don't consider it as an extra character

    At any index, if we consider a char as an extra char, then will consider the substring starting from i+1th index and continue the process on same recursively.

    At any index, if we don't consider a char as an extra char, increment the j till we get the substring which matches with the substring present in dict, then will consider the substring starting from j+1 index and continue the process on the same recursively.
    The option from which we'll get minimum no. of extra characters will be our answer.

    We can convert the existing dict into set to search if a substring present or not effectively.
*/
//------------ Approach 1 ------------//
// Recursion 
// TLE
class Solution {
public:

    int helper(int i, string s, set<string>& st, int n){
        //if index reach to the end of s
        if(i>=n){
            return 0;
        }

        //include current index/ char
        int result = 1 + helper(i+1, s, st, n);

        //exclude current index/ char
        for(int j=i;j<s.size();j++){
            string substring = s.substr(i, j-i+1);
            if(st.count(substring)!=0){
                //valid substring
                result = min(result, helper(j+1, s, st, n));
            }
        }
        return result;

    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        //converting dict into a set for searching substring effectively
        set<string> st(dictionary.begin(), dictionary.end());

        int startIndex = 0;

        return helper(startIndex, s, st, n);
    }
};


//--------- Approach 2 ---------//
// Memoisation | Top-Down Appraoch

class Solution {
public:

    int helper(int i, string s, set<string>& st, int n, vector<int>& dp){
        //if index reach to the end of s
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        //include current index/ char
        int result = 1 + helper(i+1, s, st, n, dp);

        //exclude current index/ char
        for(int j=i;j<s.size();j++){
            string substring = s.substr(i, j-i+1);
            if(st.count(substring)!=0){
                //valid substring
                result = min(result, helper(j+1, s, st, n, dp));
            }
        }
        dp[i] = result;
        return dp[i];

    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        //converting dict into a set for searching substring effectively
        set<string> st(dictionary.begin(), dictionary.end());

        int startIndex = 0;

        //initialising a dp array, initialised with -1
        vector<int> dp(n, -1);

        return helper(startIndex, s, st, n, dp);
    }
};


//---------- Approach 3 ----------//
// Tabulation | Bottom Up Approach | Pending
