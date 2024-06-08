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

//---------- Approach 2 -----------//
//at each position, to check if by adding value at that position with index combined can reach to the end
class Solution {
public:
    bool canJump(vector<int>& nums) {
       //base case
       if(nums.size()==1){
        return true;
       }
       int maxReachIndex = nums[0];

       for(int i=0;i<nums.size();i++){
        //condition 1
        //if maxReach is at last index, return true
        if(maxReachIndex>=nums.size()-1){
            return true;
        }

        //condition 2
        //if encountered 0 and its not at the last index, you're stuck, return false
        if(nums[i]==0 && i==maxReachIndex){
            return false;
        }

        //condition 3
        //if maxReach is less than currentReach at specific index, update maxReach
        int currentReachIndex = i + nums[i];
        maxReachIndex = max(maxReachIndex, currentReachIndex);
       }
       return false;        
    }
};


//peeding: DP
