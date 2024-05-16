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



    }
};
