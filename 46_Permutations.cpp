class Solution {

    void recurrPermutation(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int freqArray[]){
        //base case (ds conmtains all the elements)
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            //if element is not occupied and not marked in freq array
            if(!freqArray[i]){
                //add that element in data str.
                ds.push_back(nums[i]);
                //marked the same as occupied in freq array
                freqArray[i] = 1;
                recurrPermutation(nums, ans, ds, freqArray);
                freqArray[i] = 0;
                ds.pop_back();
            }
        }

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freqArray[nums.size()];
        for(int i=0;i<nums.size();i++){
            freqArray[i]=0;
        }
        recurrPermutation(nums, ans, ds, freqArray);
        return ans;
    }
};
