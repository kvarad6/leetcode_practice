//----------- Approach 1 -----------//
//Based on observation | AND operator will only decrease the value of result.
//So we need to find the longest consecutive length of the maximum element of nums.
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //find the maxValue
        int maxElement = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(maxElement<nums[i]){
                maxElement = nums[i];
            }
        }

        //find the freq. of max value and return the same
        int maxSubarrayLength=0;
        int currentSubarrayLength=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxElement){
                currentSubarrayLength++;
                maxSubarrayLength = max(maxSubarrayLength, currentSubarrayLength);
            }
            else{
                maxSubarrayLength = max(maxSubarrayLength, currentSubarrayLength);
                currentSubarrayLength = 0;
            }
        }
        return maxSubarrayLength;
    }
};

//----------- Approach 2 ----------//
//Using the same observation, but solving in single traversal
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = 0;
        //result -> length of the max sequence
        int result = 0;
        int streak = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxValue){
                maxValue = nums[i];
                streak = 0;
                result = 0;
            }
            if(nums[i]==maxValue){
                streak++;
            }else{
                streak=0;
            }
            result = max(streak, result);
        }
        return result;
    }
};
