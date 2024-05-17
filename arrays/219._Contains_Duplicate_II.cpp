//------------ Approach 1 ------------//
// bruite force
// TC: O(N^2)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0;
        int j = nums.size()-1;
        int difference = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    if(abs(i-j)<=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//---------- Approach 2 ----------//
//using hashmap
//TC: O(N)
//SC: O(N)

//update: if (i - map[nums[i]] <= k) | abs not needed
//reason: any index stored in the unordered map will exclusively be less than or equal to i
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            //to check if element found before
            if(mpp.count(nums[i])!=NULL){
                //check for condition
                // if(abs(i-mpp[nums[i]])<=k){
                if (i - mpp[nums[i]] <= k){
                    return true;
                }
            }
            //if element not covered before, insert the same
            // and if the number is already present in the map, then update the position of that number
            mpp[nums[i]] = i;
        }
        return false;
    }
};

//---------- Approach 3 ----------//
//sliding window
//to find value in a certain range of indices in the nums array -> sliding window
//when the size of the window increases than the given size then remove element at the front of the window
//two steps:
//if abs(i-j)>k -> shrink the window from ith end
//before shrinking, remove the element from set

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_set<int> st;
       int i=0;
       int j=0;

       while(j<nums.size()){
        //check for condition
        if(abs(i-j)>k){
            st.erase(nums[i]);
            i++;
        }

        //if element found in past, within window size
        if(st.find(nums[j])!=st.end()){
            return true;
        }
        //otherwise add that element in set and increase window size
        st.insert(nums[j]);
        j++;
       }
       return false;
    }
};



