class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //Using two pointer approach..
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0;
        int j = 0;
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        
        while(i<nums1_size && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
