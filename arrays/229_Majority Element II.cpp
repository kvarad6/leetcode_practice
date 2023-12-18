class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        //-------- Approach 1 --------------//
        //Using Hashmap | unordered map
        //TC: O(NlogN)
        //SC: O(1)
        
        vector<int> result;
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        for(auto x: mpp){
            if(x.second>n/3){
                result.push_back(x.first);
            }
        }
        return result;
    }
};
