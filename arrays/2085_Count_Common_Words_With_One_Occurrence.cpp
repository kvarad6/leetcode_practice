class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        //initialising an hashmap to store words1 words with their frequencies 
        unordered_map<string, int> mpp1;

        //initialising an hashmap to store words2 words with their frequencies
        unordered_map<string, int> mpp2;

        //iterating words1 and updating the hashmap mpp1
        for(int i=0;i<words1.size();i++){
            mpp1[words1[i]]++;
        }

        //iterating words2 and updating the hashmap mpp2
        for(int i=0;i<words2.size();i++){
            mpp2[words2[i]]++;
        }

        int count = 0;
        //iterating hashmap and updating count of words with one occurrence
        for(auto it: words1){
            if(mpp1[it]==1 && mpp2[it]==1){
                count++;
            }
        }
        return count;
    }
};
