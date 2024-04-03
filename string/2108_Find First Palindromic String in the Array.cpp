//------------ Approach 1 ------------//
// Using reverse keyword

class Solution {
public:
    bool checkPalidrome(string word){
        string reverseWord=word;
        reverse(word.begin(), word.end());
        if(word==reverseWord){
            return true;
        }
        return false;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(checkPalidrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};

//------------ Approach 2 ------------//
// Using two pointers

class Solution {
public:
    bool checkPalidrome(string word){
        int i=0;
        int j=word.size()-1;

        while(i<=j){
            if(word[i]==word[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(checkPalidrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};
