//--------------- Approach 1 ---------------//
// (left product) * (right product) 
// TC: O(n^2) | TLE

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int leftProduct = 1;
        int rightProduct = 1;

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                leftProduct *= nums[j];
            }
            for(int k=i+1;k<nums.size();k++){
                rightProduct *= nums[k];
            }
            ans.push_back(leftProduct * rightProduct);
            leftProduct = 1;
            rightProduct = 1;
        }
        return ans;
    }
};

//------------ Approach 2 ---------------//
// To reduce TC, use space | seperate arrays for left and right product
// TC: O(N) | Dynamic Programming Approach(tabulation)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        //left and right arrays are used to store prefix and postfix product of every position respectively.
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }
        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
    }
};
