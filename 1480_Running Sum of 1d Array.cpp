class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        for(int i=0;i<size;i++){
            sum = sum + nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};
