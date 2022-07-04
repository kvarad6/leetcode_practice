class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Using hashmap (unordered map)..
        
        unordered_map<int,int> mpp;
        //vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
           if(mpp.find(target-nums[i])!=mpp.end()){
               // ans.push_back(mpp[target-nums[i]]);
               // ans.push_back(i);
               return {mpp[target-nums[i]], i};
           }
           else{
               mpp[nums[i]] = i;
           }
            
        }
        return {};
    }
};
