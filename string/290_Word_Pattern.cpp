//----------- Appraoch 1 ------------//
// Using unordered map (for mapping) + set (for validation | to check if words in s already mapped)

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word = "";
        vector<string> str;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                str.push_back(word);
                word="";
            }
            else{
                word += s[i];
            }
        }
        //push the last word
        str.push_back(word);

        //edge case
        if(str.size()!=pattern.size()){
            return false;
        }

        //mapping chars in pattern to the words in s (words in str vector)
        //if mpp[pattern[i]] != str[i] -> return false

        //we can have a set, so whwnever inserting value in map, insert it in set as well | to check if words in s already mapped
        //if count(word) in set > 0 -> return false | case: two keys with same value
        unordered_map<char, string> mpp;
        set<string> st;

        for(int i=0;i<pattern.size();i++){
            if(mpp.find(pattern[i])!=mpp.end()){
                if(mpp[pattern[i]]!=str[i]){
                    return false;
                }
            }
            else{
                if(st.count(str[i])>0){
                    return false;
                }
                mpp[pattern[i]]=str[i];
                st.insert(str[i]);
            }
        }
        return true;


        

//------------ Approach 2 ------------//

//step 1: 
//fetch words from string s, by taking reference of space
//don't forget to add last word as "s does not contain any trailing spaces."

//step 2:
//Using two unordered maps
//mpp1 -> mapping of pattern->s | <char, string>
//mpp2 -> mapping of s->pattern | <string, char>
//In case of bijection/ full match of strings, both mappings should be equal

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        string word = "";

        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                str.push_back(word);
                word = "";
            }
            else{
                word += s[i];
            }
        }
        //push last word
        str.push_back(word);

        //edge case 
        if(str.size()!=pattern.size()){
            return false;
        }

        unordered_map<char, string> mpp1;
        unordered_map<string, char> mpp2;

        for(int i=0;i<pattern.size();i++){
            if(mpp1.find(pattern[i])!=mpp1.end()){
                if(mpp1[pattern[i]]!=str[i]){
                    return false;
                }
            }

            if(mpp2.find(str[i])!=mpp2.end()){
                if(mpp2[str[i]]!=pattern[i]){
                    return false;
                }
            }

            mpp1[pattern[i]] = str[i];
            mpp2[str[i]] = pattern[i];
        }

        return true;
    }
};



    }
};
