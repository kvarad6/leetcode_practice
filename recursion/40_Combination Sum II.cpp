class Solution {

private:
    void solve(vector<int> candidates, int index, int target, vector<vector<int>>&res, vector<int> &ds){
        if(target==0){
            res.push_back(ds);
            return;
        }


        for(int i=index;i<candidates.size();i++){
            //if current element is greater than target, do not consider it
            if(candidates[i]>target){
                break;
            }

            //To avoid picking up the duplicates elements
            if(i>index && candidates[i] == candidates[i-1]){
                continue;
            }

            ds.push_back(candidates[i]);
            solve(candidates, i+1, target-candidates[i], res, ds);
            ds.pop_back();
        }
        
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int>ds;
        int index = 0;
        solve(candidates, index, target, res, ds);
        return res;
    }
};
