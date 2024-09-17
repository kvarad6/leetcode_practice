
//---------- Approach 1 ----------//
//-> concatinating given strings into a single string
//-> storing freq of each word in the hashmap
//-> checking the words having freq 1

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> uncommon;
        string s3 = s1+" "+s2;
        
        unordered_map<string, int> mpp;
        string word = "";
        for(int i=0;i<s3.size();i++){
            if(s3[i]==' '){
                //This automatically handles both cases: if the word is not in the map, it's added with a count of 1; if it's already there, the count is incremented.
                mpp[word]++;
                word="";
            }else{
                word += s3[i];
            }

        }
        //inserting last word
        mpp[word]++;

        for(auto it: mpp){
            if(it.second == 1){
                uncommon.push_back(it.first);
            }
        }
        return uncommon;
    }
};
