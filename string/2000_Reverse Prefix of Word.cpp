class Solution {
public:
    string reversePrefix(string word, char ch) {
        string prefix = "";
        string suffix = "";
        string ans = "";
        bool flag = false;
        
        for(int i=0;i<word.length();i++){
            prefix += word[i];
            if(word[i]==ch){
                flag = true;
                break;
            }
            else{
                ans += word[i];
            }
        }
        if(flag==true){
            reverse(prefix.begin(), prefix.end());
        }
        
        for(int i=prefix.size();i<word.length();i++){
            suffix += word[i];
        }
        ans = prefix + suffix;

        return ans;
        
    }
};
