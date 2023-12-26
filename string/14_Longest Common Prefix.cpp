//---------------- Approach 1 --------------//
//Using two pointers..
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        //To check each character present in first string with the all the other words one by one, char by char.

        string ans;
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<strs.size();j++){
                if(strs[0][i]!=strs[j][i]){
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
    }
};

//---------------- Appraoch 2 ----------------//
// Using Trie  |   Pending
