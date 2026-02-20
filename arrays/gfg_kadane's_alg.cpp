/* Keep extending your current subarray as long as it stays positive; 
 the moment it turns negative, abandon it and start over. 
 Track the best sum seen at any point.
 */
 
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int currentSum = 0;
        int maxSum = INT_MIN;
        
        //if sum<0, make sum 0
        for(int i=0;i<arr.size();i++){
            currentSum += arr[i];
            maxSum = max(maxSum, currentSum);
            if(currentSum<0){
                currentSum=0;
            }
        }
        return maxSum;
    }
};
