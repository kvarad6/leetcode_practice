class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //base cases
        // if(nums.size()==0){
        //     nums1 = nums2;
        // }
        //-------- Approach 1 --------//
        //TC: O(m+n)log(m+n)
        //SC: O(1)

        // replacing all the 0's of nums1 with nums2 elements and sorting nums1..
        int i = m;
        for(int j=0; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(), nums1.end());

        //---------- Approach 2 -----------//
        //TC: O(m+n)
        //SC: O(1)

        //Two pointer ..
        //i -> starts from largest nonzero num1 element
        //j -> starts from largest num2 element
        //k -> starts from the last element of num1

        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        //if any of the index goes out of bound, we'll stop..       
        while(i>=0 && j>=0){

            //if ith of nums1 is greater than jth of num2,
            // kth element will be replaced by ith element.
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }

            //else as ith of nums1 is smaller or equal than jth of num2,
            // kth element will be replaced by jth element.
            else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        //inserting remaining elements of nums2 in nums1..
        while(j>=0){
            nums1[k] = nums2[j];
            j--; k--;
        }
        
    }
};
