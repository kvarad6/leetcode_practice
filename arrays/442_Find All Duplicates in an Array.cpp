//--------------- Approach 1 -------------------//
// using hashmap and extra space (array to store result)
//Time Complexity : O(n)
//Space Complexity : O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        //option 1:
        // for (const auto& [key, value] : mpp) {
        //     if (value == 2) {
        //     // Push the key to the vector if the value is 2
        //     ans.push_back(key);
        //     }
        // }

        //option 2:
        for(auto it: mpp){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};


//--------------- Approach 2 -------------------//
// using set and array
// Time Complexity : O(n)
// Space Complexity : O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> st;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            //if element is already present in set, add it in ans array
            if(st.count(nums[i])!=NULL){
                ans.push_back(nums[i]);
            }
            //if element is not already present in set, add it
            else{
                st.insert(nums[i]);
            }
        }
        return ans;
    }
};
