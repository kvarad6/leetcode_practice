class Solution {
  public:
  //bruite force thinking: 
  //sort both the arrays -> 
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2) {
        //initialise vector of pair
        vector<pair<int, int>> result;
        
        //sort the first array
        sort(arr1.begin(), arr1.end());
        
        //initialise a hashmap and insert second array into the hashmap
        unordered_map<int, int> mpp;
        for(int i=0;i<arr2.size(); i++){
            mpp[arr2[i]]++;
        }
        
        //for ith element, search of target-ith element present in arr2
        for(int i=0;i<arr1.size();i++){
            if(mpp.find(target-arr1[i])!=mpp.end()){
                // result.push_back({arr1[i], target-arr1[i]});
                // Add the pair mpp[complement] times (for each occurrence in arr2)
                for(int j = 0; j < mpp[target-arr1[i]]; j++){
                    result.push_back({arr1[i], target-arr1[i]});
                }
            }
        }
        return result;
    }
};
