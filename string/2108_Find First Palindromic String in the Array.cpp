class Solution {
public:
    bool isPalidrome(string word){
        string reverseWord = word;
        reverse(word.begin(), word.end());
        if(word == reverseWord){
            return true;
        }
        else{
            return false;
        }
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(isPalidrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};
