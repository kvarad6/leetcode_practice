class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        //------------------- Appraoch 1 ---------------------//
        //Using hashmap (unordered map) and stack

        //initialising array with -1s so that for the element whose next greater element is not present, that will remain -1.
        vector<int> ans(nums1.size(), -1);
        stack<int> st;
        unordered_map<int, int> mpp;

        // In the second array (nums2), find the next immediate greater element for all the numbers one by one.
        // map the number to its next greater and store using unordered map..
        //e.g: element 1 ---> next greater 2
        //     element 2 ---> next greater 3

        for(int i=0;i<nums2.size();i++){
            int element = nums2[i];
            while(!st.empty() && element > st.top()){
                mpp[st.top()] = element;
                st.pop();
            }
            st.push(element);
        }

        //transverse nums1 array and search key in map (from num1) and store curresponding mapped value (replace the index and -1 value) in ans array.

        for(int i=0;i<nums1.size();i++){
            int key = nums1[i];

            if(mpp.find(key)!=mpp.end()){
                int nextGreaterEle = mpp[key];
                ans[i] = nextGreaterEle;
            }
        }
        return ans;
    }
};
