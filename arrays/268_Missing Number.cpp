class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        //Approach 1 (space: O(1), time: O(n))
        int n = nums.size();
        int sum = 0;
        int total = n*(n+1)/2;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        return total-sum;
        
        
        //Approach 2 : using XOR
        //If index is similar to the number, using xor, it will get cancel out.
        int missing = 0;
        for(int i=0;i<nums.size();i++){
            missing ^= i;               //XOR with index i
            missing^= nums[i];          //XOR with nums[i]
        }
        missing^= nums.size();          //XOR with size
        return missing;
    }
};
