class Solution {
public:

//------ Approach 1 | Using Heapify/ Heap Sort (Priority Queue) -----------//
//Heap Sort: Array -> Heap -> Sort

//TC: O(N)
//SC: O(1)

    // function to convert the tree present below "i" into heap
    void heapify(vector<int>& nums, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        //to check the overflow condition, checking if left crosses n
        //also checking if left element is greater than current largest
        if(left<n && nums[left]>nums[largest]){
            largest = left;
        }

        //to check the overflow condition, checking if right crosses n
        //also checking if right element is greater than current largest
        if(right<n && nums[right]>nums[largest]){
            largest = right;
        }

        //if current element is not the largest, swap it with the largest and call heapify function for the tree below that node..
        if(largest!=i){
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }


    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // heapify stage
        //It will convert array to heap (max heap) and largest element become at root/ start of the array
        for(int i=n/2-1;i>=0;i--){
            heapify(nums, n, i);
        }

        // sorting stage
        //starting from the largest (first element) and swap with the last one 
        //and calling heapify function fot the remaining part of the array
        for(int i = nums.size() - 1; i > 0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};
