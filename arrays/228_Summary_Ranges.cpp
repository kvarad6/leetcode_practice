//----------- Approach 1 -----------//
//Using two pointers | prevIndex, currentIndex
//No need to add all the elements in a sequence,
//Just need to add start and end index element with str: "start->end"

//TC: O(N)
//SC: O(N)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int prevIndex = 0, currentIndex = 0;
        string currentRange = "";

        for(int i=1; i<=nums.size();i++){
            //haven't written "nums[i]-nums[i-1]==1, to avoid signed integer overflow"
            if(i<nums.size() && nums[i]==nums[i-1] + 1){
                continue;
            }
            else{
                currentIndex = i-1;
                
                if(prevIndex==currentIndex){
                    //if range has only one element
                    currentRange = to_string(nums[prevIndex]);
                    ans.push_back(currentRange);
                }
                else{
                    //if the range has more than one element
                    currentRange = to_string(nums[prevIndex]) + "->" + to_string(nums[currentIndex]);
                    ans.push_back(currentRange);
                }   
                prevIndex = i;
            }
        }
        return ans;
    }
};
