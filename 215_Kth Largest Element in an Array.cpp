class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        // ----------- Approach 1 --------------//

        //Using priority queue | maxHeap

        priority_queue<int> pq(nums.begin(), nums.end());
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        for(int i=0;i<k-1;i++){
            pq.pop();
            }
        
        return pq.top();

        //---------------- Approach 2 ----------------//
        //Using priority queue | minHeap
        //By default, priority queue implements maxHeap, so inorder to implement minHeap, we need to multiply elements with "-1" before storing them in queue.

        priority_queue<int> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(-1* nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return -1*pq.top();

    }
};
