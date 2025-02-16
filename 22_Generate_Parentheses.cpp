//-------- Approach 1 ---------//
//TC: 2n*(2^2n)
class Solution {
public:
    vector<string> result;

    bool isValid(string s){
        int counter = 0;
        for(auto &ch: s){
            if(ch=='('){
                counter++;
            }else{
                counter--;
            }
            if(counter<0){
                return false;
            }
        }
        if(counter==0){
            return true;
        }
        return false;
    }

    void solve(int n, string curr){

        //base case
        if(curr.length()==2*n){
            if(isValid(curr)){
                result.push_back(curr);
            }
            return;
        }

        //backtracking | Do -> Explore -> Undo
        //option 1: insert open bracket first
        curr.push_back('(');
        solve(n, curr);
        curr.pop_back();

        //option 2: insert closed bracket first
        curr.push_back(')');
        solve(n, curr);
        curr.pop_back();  
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(n, curr);
        return result;
    }
};

//-------- Approach 2 ---------//
/*
-> Optimised approach
-> Instead of checking and generating each and every combination, add some safety checks in between:
valid cases: 
if(open < n) -> solve()
if(close < open) -> solve()

no need to valid function as passing the valid combinations only

TC: O(2^n) | need to learn about catalan number
SC: O(n)
*/

class Solution {
public:
    vector<string> result;

    void solve(int n, string curr, int open, int close){

        //base case
        if(curr.length()==2*n){
            result.push_back(curr);
            return;
        }

        //backtracking | Do -> Explore -> Undo
        //option 1: insert open bracket first
        if(open<n){
            curr.push_back('(');
            solve(n, curr, open+1, close);
            curr.pop_back();
        }

        //option 2: insert closed bracket first
        if(close<open){
            curr.push_back(')');
            solve(n, curr, open, close+1);
            curr.pop_back();
        }  
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        int open = 0;
        int close = 0;
        solve(n, curr, open, close);
        return result;
    }
};
