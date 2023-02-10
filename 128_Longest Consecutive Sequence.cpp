class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int longestSeq = 0;

        for(int i=0;i<nums.size();i++){
            //check if previous element is present in the set
            if(s.find(nums[i]-1) != s.end()){
                continue;
            }
            //if previous element is not present in the set, then consider present number as currentElement and sequence will start from that number.
            else{
                int count = 0;
                int currentElement = nums[i];
                while(s.find(currentElement)!=s.end()){
                    count++;
                    currentElement++;
                }
                
                longestSeq = max(longestSeq, count);
            }
        }
        return longestSeq;
    }
};
