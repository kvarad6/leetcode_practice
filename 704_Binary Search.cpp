class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int total_elements = nums.size()-1;
        int low = 0;
        int high = total_elements;
        
        while(low<=high){
            int middle = low + (high-low)/2;
            if(nums[middle]==target){
                return middle;
            }
            else if(nums[middle]>target){
                high = middle-1;
            }
            else{
                low = middle + 1;
            }
        }
        return -1;
    }
};
