//----------- Approach 1 -----------//
//Backtracking | unordered_map

class Solution {
public:

    void helper(vector<vector<int>> &ans, vector<int> &permutation, unordered_map<int, int> mpp, vector<int> &nums){
        //if filled all the elements in permutation array, add that permutation in the ans vector
        if(permutation.size()==nums.size()){
            ans.push_back(permutation);
            return;
        }

        //recursively select one element from the original nums array at a time, recursively access the combination, store it in the permutation array, backtrack from that and access another one
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==0){
                permutation.push_back(nums[i]);
                mpp[nums[i]] = 1;
                helper(ans, permutation, mpp, nums);
                mpp[nums[i]] = 0;
                permutation.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        //initia ans vector of vector
        vector<vector<int>> ans;

        //declare an array to store various combinations
        vector<int> permutation;

        //initialising a freq array
        unordered_map<int, int> mpp;

        //initialising map with 0
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=0;
        }

        helper(ans, permutation, mpp, nums);
        return ans;
    }
};


//----------- Approach 2 -----------//
//Backtracking | freq array

class Solution {
public:

    void helper(vector<vector<int>> &ans, vector<int> &permutation, vector<int> &freq, vector<int> &nums){
        //if filled all the elements in permutation array, add that permutation in the ans vector
        if(permutation.size()==nums.size()){
            ans.push_back(permutation);
            return;
        }

        //recursively select one element from the original nums array at a time, recursively access the combination, store it in the permutation array, backtrack from that and access another one
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                permutation.push_back(nums[i]);
                freq[i] = 1;
                helper(ans, permutation, freq, nums);
                freq[i] = 0;
                permutation.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        //initia ans vector of vector
        vector<vector<int>> ans;

        //declare an array to store various combinations
        vector<int> permutation;

        //initialising a freq array
        vector<int> freq(nums.size(), 0);

        helper(ans, permutation, freq, nums);
        return ans;
    }
};
