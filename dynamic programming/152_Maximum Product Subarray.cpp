//Bruit force approach | O(n^2)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_product = INT_MIN;
        int current_product;

        for(int i=0;i<n;i++){
            current_product = 1;
            for(int j=i;j<n;j++){
                current_product *= nums[j];
                if(current_product>max_product){
                    max_product = current_product;
                }
            }
        }
        return max_product;
    }
};

//optimised approach | DP
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxProduct = INT_MIN;
        int currentProduct;

        for(int i=0;i<n;i++){
            //when current element is 0, start a new subarray product
            if(prefix==0){
                prefix = 1;
            }
            if(suffix==0){
                suffix = 1;
            }
            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];
            currentProduct = max(prefix, suffix);
            maxProduct = max(maxProduct, currentProduct);

        }
        return maxProduct;
    }
};
