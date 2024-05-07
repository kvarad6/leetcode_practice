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
// using set and array | set -> unique + sorted
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


//-------------- Approach 3 -------------------//
//without using extra space
//using index -> each element represent a position in array | 1<=nums[i]<=n
//while traversing the array, if you come back to the same position -> duplicate
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            //index to check -> abs(nums[i]-1) 
            //if positive -> mark it as visited by making it negative
            //if negative -> already visited -> abs(nums[i]) -> duplicate
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1] *= -1;
            }
            else{
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }
};
