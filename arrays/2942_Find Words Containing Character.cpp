class Solution {
public:
    bool findChar(string word, char x){
        for(int i=0;i<word.size();i++){
            cout<<word[i];
            cout<<x;
            if(word[i] == x){
                return true;
            }
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
           if(findChar(words[i], x)==true){
               ans.push_back(i);
           }
        }
        return ans;
    }
};
