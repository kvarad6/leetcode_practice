class Solution {

//Using Include - Exclude method..

private:
    void solve(vector<int> nums, vector<vector<int>>& ans, int index, vector<int> output){
        //base case (here, we get all the subsets..)
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        
        //exclude
        solve(nums, ans, index+1, output);

        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, ans, index+1, output);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        vector<int> output;

        solve(nums, ans, index, output);
        return ans;
    }
};
