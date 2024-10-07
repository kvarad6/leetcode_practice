//----------- Approach 1 ----------//
/*
-> Using stack
-> TC: O(N)
-> SC: O(N)
*/
class Solution {
public:
    int minLength(string s) {
        if(s.size()==0 || s.size()==1){
            return s.size();
        }
        stack<char> st;
        st.push(s[0]);
        //transversing the string and inserting chars in the stack
        for(int i=1;i<s.size();i++){
            if(!st.empty() && st.top()=='A' && s[i]=='B'){
                st.pop();
            }else if(!st.empty() && st.top()=='C' && s[i]=='D'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        return st.size();
    }
};
