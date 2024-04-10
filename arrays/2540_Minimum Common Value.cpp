//------- Approach 1 -------//
//Using Set
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        //inserting nums1 element into the set
        for(auto it: nums1){
            st.insert(it);
        }

        //inserting nums2 element into the set 
        //if common element found, return 

        for(auto it: nums2){
            if(st.count(it)!=0){
                return it;
            }
        }
        return -1;
    }
};

//-------- Approach 2 --------//
//Using two pointers

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }
            if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};
