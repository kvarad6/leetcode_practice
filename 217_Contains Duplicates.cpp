
// 217. Contains Duplicate



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        // Using sorting..(Time Complexity: nlog(n))
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
        */
        
        //Using Map..(Time Complexity: O(n))
        
        map<int, int> m;
        
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])==0){
                m[nums[i]]++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
