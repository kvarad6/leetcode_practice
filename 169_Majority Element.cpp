class Solution {
public:
    int majorityElement(vector<int>& nums) {


        //-------------- Approach 1: -----------------------//

        //element occurs more than n/2 times -> always occupy middle position
        //Sort the array -> find middle element

        // sort(nums.begin(), nums.end());

        // int n = nums.size();
        // return nums[n/2];

        //---------------- Approach 2 ----------------------//

        //Using Hashmap | unordered_map

        unordered_map<int, int> mpp;

        int n = nums.size();

        //record frequency of elements..
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        //check if element occurs more than n/2 times..

        n = n/2;
        for(auto x: mpp){
            if(x.second>n){
                return x.first;
            }
        }
        return 0;

        //---------------- Approach 3 --------------------//

        //Moore Voting Algorithm -> pending...

    }
};
