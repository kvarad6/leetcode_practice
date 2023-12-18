class Solution {
    //using extra space | frequency array

    void recursiveSol(vector<int>& nums, vector<vector<int>> &ans, vector<int> &ds, int freq[]){
        //base case
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        //recursive sol
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                recursiveSol(nums, ans, ds, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i] = 0;
        }
        recursiveSol(nums, ans, ds, freq);
        return ans;
    }
};

class Solution {
    //without using any extra space 
    
    void recursiveSol(vector<int>& nums, vector<vector<int>> &ans, int index){
        //base case
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        //recursive sol
        for(int i=index;i<nums.size();i++){
            swap(nums[index], nums[i]);
            recursiveSol(nums, ans, index+1);

            //reswapping it for the next permutation
            swap(nums[index], nums[i]);

        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        recursiveSol(nums, ans, index);
        return ans;
    }
};
