class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //Using Reverse array technique.
        
        k %= nums.size();     //Taking modulus (required when k>no. of elements)
        
        reverse(nums.begin(), nums.end());     //first reverse entire array 
        reverse(nums.begin(), nums.begin()+k);  // Reverse k elements from start
        reverse(nums.begin()+k, nums.end());    //Reverse n-k elements (n-> size)
        
        //TC: O(n)
        //SC: O(1)
        
        
    }
};
