class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Using kadane's alg..

        int sum = 0;
        int maxi = nums[0];

        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            //if current sum is greater than maximum sum, then the current sum becomes the maximum sum
            if(sum>maxi){
                maxi = sum;
            }

            if(sum<0){
                sum = 0;
            }
            
        }
        return maxi;
    }
};
