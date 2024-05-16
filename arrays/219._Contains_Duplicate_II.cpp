//------------ Approach 1 ------------//
// bruite force
// TC: O(N^2)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0;
        int j = nums.size()-1;
        int difference = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    if(abs(i-j)<=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//---------- Approach 2 ----------//
//using hashmap
//TC: O(N)
//SC: O(N)

//update: if (i - map[nums[i]] <= k) | abs not needed
//reason: any index stored in the unordered map will exclusively be less than or equal to i
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            //to check if element found before
            if(mpp.count(nums[i])!=NULL){
                //check for condition
                // if(abs(i-mpp[nums[i]])<=k){
                if (i - mpp[nums[i]] <= k){
                    return true;
                }
            }
            //if element not covered before, insert the same
            // and if the number is already present in the map, then update the position of that number
            mpp[nums[i]] = i;
        }
        return false;
    }
};

//---------- Approach 3 ----------//
//sliding window



