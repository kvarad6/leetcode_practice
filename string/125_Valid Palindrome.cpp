//------------ Approach 1 ------------//
//isalnum() -> to check if char is alphanumeric or not
//if not alphanumeric -> skip it and move pointer to next
//if alphanumeric -> convert start and endth char to lowercase and compare

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start<=end){
            if(isalnum(s[start])==false){
                start++;
                continue;
            }
            if(isalnum(s[end])==false){
                end--;
                continue;
            }

            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }else{
                start++;
                end--;
            }
        }
        return true;
    }
};
