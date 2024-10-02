//----------- Approach 1 ---------//
/*
Bruite Force
Step 1: Sort the array
Step 2: Store the element and curresponding rank in a hashmap
Step 3: Transverse the original array, insert the rank in seperate array, return that array.
*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        //store the original array into another temp array and sort that temp array
        vector<int> temp(n,0);
        for(int i=0;i<arr.size();i++){
            temp[i] = arr[i];
        }

        //Another way to assign array | direct assignment:
        // vector<int> temp = arr;

        //sort the temp array
        sort(temp.begin(), temp.end());

        //initialising a hashmap to store the rank
        unordered_map<int, int> mpp;
        int rank = 1;
        for(int i=0;i<n;i++){ 
            if(mpp[temp[i]]==0){
                mpp[temp[i]] = rank++;
            }
             //Another way:
            // if(mpp.find(temp[i])==mpp.end()){
            //     mpp[temp[i]] = rank++;
            // }
        }

        //transverse the original array, put the rank in new vector, return that vector
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            ans[i] = mpp[arr[i]];
        }
        return ans;
    }
};
