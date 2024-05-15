class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m)return false;
        map<char,char>mpp1;
        map<char,bool>mpp2;
        
        for(int i=0;i<n;i++){
        //if the character at index i in the string s (denoted by s[i]) does not exist as a key in the umap
        //!mpp1[s[i]] -> the key s[i] is not found in mpp1
        if(!mpp1[s[i]]){

            //checks if the character at index i in the string t (denoted by t[i]) does not exist as a key in the two
            //!mpp2[t[i]] -> the key t[i] is not found in "mpp2" map
            if(!mpp2[t[i]]){
                mpp1[s[i]]=t[i];
                mpp2[t[i]]=1;
            }else {
                return false;
            } 
        }else{
            if(mpp1[s[i]]!=t[i])return false;
        }      
        }
        return true;
    }
};
