//----------- Approach 1 --------//
/*
-> We don't need to actually swap the characters in the string. We just need to count how many steps it would take to move all '0's to the left.
The key insight is that for each '0', we need to move it past all the '1's that are to its left.
*/
class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        int ones = 0;

        //traverse the string
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ones++;
            }else{
                count += ones;
            }
        }

        return count;
    }
};
