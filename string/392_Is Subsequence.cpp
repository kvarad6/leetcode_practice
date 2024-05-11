//------------- Approach 1 -------------//
//Two pointers
//check if all elements of s present in t
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;

        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i == s.size() ? true : false;

    }
};
