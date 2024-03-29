class Solution {
public:
    string customSortString(string order, string s) {
        string result = "";
        unordered_map<char, int> mpp;
        for(auto it : s){
            mpp[it]++;
        }

    //Iterate through the characters in order. For each character:
    // If the character exists in s, append it to the result string the same number of times it appears in s, and then erase it from the hashmap.
        for(auto it : order){
            if(mpp.find(it)!=mpp.end()){
                result.append(mpp[it], it);
                mpp.erase(it);
            }
        }

        //After iterating through order, append any remaining characters from the hashmap to the result string.
        for(auto &it : mpp){
            //it.first -> char
            //it.second -> frequency
            result.append(it.second, it.first);
        }

        return result;
    }
};
