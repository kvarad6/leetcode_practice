class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //1. Using sorting..
        
        if(s.size()!=t.size()){
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s==t){
            return true;
        }
        return false;
        
        //2. Using Hashmap
        
        if(s.size()!=t.size()){
            return false;
        }
        
        unordered_map<char, int>mpp;
        for(char c:s){
            mpp[c]++;
        }
        for(char c:t){
            mpp[c]--;
            if(mpp[c]<0){
                return false;
            }
        }
        return true;
        
    }
};
