//------------- Approach 1 --------------//
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

//------------------- Approach 2 -------------------//
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mpp;
        string result = "";

        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        for (int i = 0; i < order.size(); i++) {
            if (mpp.find(order[i]) != mpp.end()) {
                // Append character based on remaining frequency
                for (int j = 0; j < mpp[order[i]]; j++) {
                    result += order[i];
                }
                mpp[order[i]] = 0;  // Decrement frequency to 0 after appending
            }
        }

        //now as we erased the elemets present in order, from map, there are elements left in map, that needs to be added in final result
        for(auto it: mpp){
            if(it.second>0){
                result += it.first;
                result.append(it.second - 1, it.first);
            }
            
        }

        return result;
    }
};
