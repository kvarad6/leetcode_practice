//----- Approach 1 ------//
//Start from back, maintain the length till you get first space.
//In case of space at endmost, maintain flag to check if lastword
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool counting = false;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]!=' '){
                length++;
                counting = true;
            }
            else if(counting==true){
                break;
            }
        }
        return length;
    }
};
