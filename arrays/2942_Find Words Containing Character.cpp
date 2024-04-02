//-------------- Approach 1 --------------//
// Bruite force
// TC: O(N^2)

class Solution {
public:
    bool findChar(string word, char x){
        for(int i=0;i<word.size();i++){
            if(word[i]==x){
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

//------------- Approach 2 -------------//
// Using npos | until end of a string
// returns -1 if no match
// TC: ~O(N)

class Solution {
public:
    bool findChar(string word, char x){
        int found = word.find(x);
        if(found!=string::npos){
            return true;
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
