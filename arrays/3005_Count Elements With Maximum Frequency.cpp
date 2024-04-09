class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto x : nums){
            mpp[x]++;
        }

        int maxi = 0;
        // Traverse through map to find the elements.
        for (auto it : mpp) {
            if(it.second > maxi){
                maxi = it.second;
            }
        }

        int ans = 0;
        for(auto it : mpp){
            if(it.second == maxi){
                ans += maxi;
            }
        }

        return ans;
    }
};
