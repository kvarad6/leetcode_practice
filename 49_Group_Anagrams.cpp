//------------ Approach 1 ------------//
//strings are anagrams <=> same string after sorting. No need for frequency count.

/*TC: 
    TC for sorting string of size k, using sort function: klog(k)
    for n strings, TC: n * klog(k)
    TC for Hashing and grouping: O(n)
    Total TC: ~ n*klog(k)
*/

/*SC:
    SC: O(n*k) as at worst case, map can hold all the unique words as keys
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        
        for(auto x : strs){
            string word = x;
            sort(word.begin(), word.end());
            mpp[word].push_back(x);
        }

        vector<vector<string>> ans;
        for(auto x: mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
