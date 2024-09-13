//------------ Approach 1 -----------//
//Calculating XOR for each pair and storing it in ans vector
//TC: O(n^2)
//SC: O(n)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        //traverse the queries 2d array
        for(int i=0;i<queries.size();i++){
            int result = 0;
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                result ^= arr[j];
            }
            ans.push_back(result);
        }
        return ans;
    }
};

//------------ Approach 2 -----------//
/*
Optimised approach | Using prefix sum
-> Creating an additional array to store the XOR from 0 to each of the element (precalculated xor)
-> if a pair starts from 0, we can directly use precalculated XOR
-> if a pair start from x and go till y, we can calculate XOR by substracting precalculated XOR till the x-1 from precalculated XOR till y
-> In this way, we need not to calculate the XOR repeatedly.

-> e.g: for the pairs [[0,1], [1,2]] -> 0^1^1^2 -> 0^2, thats why pre[j]^pre[i-1]
*/
//TC: O(n+m) | n-> size of arr | precalculated array size
//SC: O(n+q) | n-> size of ans vector + q-> size of precalculated array
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //initialising a vector to store the resultant xor of each pair
        vector<int> ans;

        int n = arr.size();
        //initialising a vector to store precalculated XORs
        vector<int> pre(n);
        pre[0] = arr[0];

        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]^arr[i];
        }

        for(int k=0; k<queries.size();k++){
            int i = queries[k][0];
            int j = queries[k][1];
            
            if(i==0){
                ans.push_back(pre[j]);
            }else{
                ans.push_back(pre[j]^pre[i-1]);
            }
        }
        return ans;

    }
};
