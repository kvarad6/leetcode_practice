class Solution {
public:
    string truncateSentence(string s, int k) {
        int spaceCount = 0;
        string ans;

        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                spaceCount++;
            }
            if(spaceCount == k){
                break;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
