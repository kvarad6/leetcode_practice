//-------------- Approach 1 | Bruite Force -------------//
// Using maxProduct, currentProduct
// TC: O(N^2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //INT_MIN as negatives can also be present in array
        int maxProduct = INT_MIN;
        int currentProduct;

        for(int i=0;i<nums.size();i++){
            currentProduct = 1;
            for(int j=i;j<nums.size();j++){
                currentProduct *= nums[j];
                if(currentProduct > maxProduct){
                    maxProduct = currentProduct;
                }
            }
        }
        return maxProduct;
    }
};

//------------- Appraoch 2 | Optimised --------------//
// Using DP
// using prefix-suffix method
// TC: O(N)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxProduct = INT_MIN;
        int currentProduct;
        for(int i=0;i<n;i++){
            //handling the case where 0 encounters.
            //when current element is 0, start a new subarray product
            //instead of carrying 0, making prefix/suffix product value to 1
            if(prefix==0){
                prefix = 1;
            }
            if(suffix==0){
                suffix=1;
            }
            //prefix starts from beggining
            prefix *= nums[i];

            //suffix starts from end
            suffix *= nums[n-i-1];

            currentProduct = max(prefix, suffix);
            maxProduct = max(maxProduct, currentProduct);
        }
        return maxProduct;
    }
};

