class Solution {
public:
    void sortColors(vector<int>& nums) {
    //----------- Approach 1 ----------------//
    //Using count of 0's, 1's and 2's approach
    //TC: 0(N) to find count + 0(N) for array modification
    //SC: 0(1) as no extra space used

        int count0=0, count1=0, count2=0;

        //finding count of 0's, 1's and 2's
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
            }
            else if(nums[i]==1){
                count1++;
            }
            else{
                count2++;
            }
        }

        //for i=0 -> count0 ---> 0's
        //for i=count0 -> count1 --->1's
        //for i=count1 -> count2 ---> 2's
        
        for(int i=0;i<count0;i++){
            nums[i] = 0;
        }
        for(int i=count0;i<count0+count1;i++){
            nums[i] = 1;
        }
        for(int i=count0+count1;i<nums.size();i++){
            nums[i] = 2;
        }
    }  

    void sortColors(vector<int>& nums) {
    //----------- Approach 2 ----------------//
    //using 3 variables | count0, count1, count2
    //optimised appraoch of putting elements
     int count0=0, count1=0, count2=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
            }
            else if(nums[i]==1){
                count1++;
            }
            else{
                count2++;
            }
        }

        //putting all the elements in a single traversal
        for(int i=0;i<nums.size();i++){
           if(i<count0){
               nums[i] = 0;
           }
           else if(i>=count0 && i<count0+count1){
               nums[i] = 1;
           }
           else{
               nums[i] = 2;
           }
        }   
    }  
};
