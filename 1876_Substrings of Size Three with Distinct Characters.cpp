class Solution {
public:
    int countGoodSubstrings(string s) {
        int i = 0;    //start of window
        int j = 0;    //end of window
        int total_unique_substrings = 0;
        int substring_size = 3;

        int string_size = s.length();
        
        while(j<string_size){
            if(j-i+1<substring_size){
                j++;
            }
            else if(j-i+1 == substring_size){                      //if window size is equal to substring size
              if(s[i]!=s[i+1] && s[i+1]!=s[j] && s[i]!=s[j]){        //if each and every character is unique
                  total_unique_substrings += 1;
              }
                j++;
                i++;
            }
        }
        return total_unique_substrings;
        
    }
};
