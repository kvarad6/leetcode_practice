//min length + condition -> sliding window problem
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0;
        int sum=0, minLength=INT_MAX;

        while(j<nums.size()){
            //add current element value to sum
            sum += nums[j];
            while(sum>=target){
                //shrink sliding window | remove starting element from window
                sum -= nums[i];

                //if minLength > current length, update
                minLength = min(j-i+1, minLength);

                //move window
                i++;
            }
            j++;
        }
        //below can be written as: return (minLength == INT_MAX) ? 0 : minLength 
        if(minLength==INT_MAX){
            return 0;
        }
        return minLength;
    }
};
