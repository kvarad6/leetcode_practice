class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //----------- Approach 1 ------------//
        //Bruite force
        //TLE

        int repeatedNumber = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    repeatedNumber = nums[i];
                }
            }
        }
        return repeatedNumber;

        //------------ Approach 2 -------------//
        //sort the array -> compare adjacent elements
        //TC: O(NlogN)
        //SC: O(1)

        //sort the array
        sort(nums.begin(), nums.end());

        int repeatedNum = 0;
        //check adjacent elements
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                repeatedNum = nums[i];
            }
        }
        return repeatedNum;

        //------------ Approach 3 -------------//
        //optimised
        //linked list cycle method | fast-slow pointer
        //starting from the 0th index, go to the element whose index = nums[0] 
        //continue till the complete array traversal
        //detecting cycle and the intersection element using fast-slow pointer

        //TC: O(N)
        //SC:O(1)

        int slow = nums[0];
        int fast = nums[0];

        //move slow and fast pointer till both collides
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        //put fast pointer to start and move both slow & fast by one step at a time
        fast = nums[0];
        //the point where they collides this time will be the duplicate element
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
