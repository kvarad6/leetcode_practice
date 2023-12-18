class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        
        int left = 0;
        int right = size-1;
        int sum = 0;
        while(left<=right){
             sum = numbers[left] + numbers[right];
             if(sum!=target){
            //As sum is exceeding target, to reduce sum, move "right" pointer to left
                if(sum > target){     
                    right--;
                }
                 else{              
          //Here, sum is less than target, move "left" pointer to right to increase the sum.
                     left++;
                 }
            }
            else{
                return {left+1,right+1};
            }
        }
           
        return {};
    }
};
