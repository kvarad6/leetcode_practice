class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Using kadane's alg..
        
        int maxSum = INT_MIN;
        int currentSum = 0;

        for(int i=0;i<nums.size();i++){
            currentSum += nums[i];

        //if current sum is greater than maximum sum, then the current sum becomes the maximum sum

            if(currentSum > maxSum){
                maxSum = currentSum;
            }
            if(currentSum < 0){
                currentSum = 0;
            }
        }
        return maxSum;
    }
};
