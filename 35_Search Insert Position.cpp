class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int total_elements = nums.size()-1;
        int high = total_elements;
        int low = 0;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};
