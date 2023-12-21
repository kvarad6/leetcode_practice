#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //------------- Appraoch 1 | HashMap + Priority Queue ------------------//

        // storing frequencies of each element present in array
        unordered_map<int, int> mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        // traverse the map and puts keys into heap on the basis of their values (frequencies)
        //pop the top element when size of heap reaches to "k"
        //return the array of remaining elements in heap

        priority_queue<pair<int,int>> pq;

        for(auto it = mpp.begin();it!=mpp.end();it++){
            //pushing pair of <frequency,distinct element of nums array> so that we get most occuring element on top
            pq.push(make_pair(it->second, it->first));
        }

        //to return top k elements, transverse the queue, pop and put it in the array.

        vector<int> ans;
        int i = 0;
        while(i<k){
            //pushing the key in array
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return ans; 
    }
};
