//----------- Approach 1 -----------//
//linear solution | greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //edge cases
        if(nums.size()==1){
            return true;
        }

        int iMaxReach = 0 + nums[0];
        int i = 1;

        while(iMaxReach>=i){
            if(iMaxReach>=nums.size()-1){
                return true;
            }
            iMaxReach = max(iMaxReach, nums[i]+i);
            i++;
        }
        return false;
    }
};

//peeding: DP
