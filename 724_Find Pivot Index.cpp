class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        int i, j, flag=0;
        int size = nums.size();
        for(i=0;i<size;i++){
            total_sum += nums[i];
        }
        
        int left_sum = 0;
        int right_sum = total_sum;
        for(j=0;j<size;j++){
            right_sum -= nums[j];
            if(left_sum==right_sum){
                return j;
            }
            left_sum += nums[j];
        }
     
     return -1;
        
    }
};
