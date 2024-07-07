
//----------- Approach 1 -----------//
//Two Pointers | method1
//TC: O(m+n)
//SC: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //i -> starts from largest nonzero num1 element
        //j -> starts from largest num2 element
        //k -> starts from the last element of num1
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        while(j>=0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

// ------------ Approach 2 -----------//
// start with the mth position, from where 0 get started
// then replace 0's with the nums2 elements
// sort the nums1 array

//TC: O(m+n)log(m+n)
//SC: O(1)

// replacing all the 0's of nums1 with nums2 elements and sorting nums1..
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m;
        for(int j=0;j<n;j++){
            nums1[i]=nums2[j];
            i++;
        }
        sort(nums1.begin(), nums1.end());
    }
};


//---------- Approch 3 ----------//
// Two pointers | method 2

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k]=nums2[j];
                k--;
                j--;
            }
        }
    }
};


