class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //---------- bruite force sol.. -----------------//
        //TC: O(n^3) | TLE
        
        to store unique triplets..
        set<vector<int>> st;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i] + nums[j] + nums[k]==0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};

                        //to avoid duplicates, sort the triplets and store in set..
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;


        // ----------- Optimal Approach ----------------//
        // Fixing third element | nums[k] = -(nums[i] + nums[j])
        // TLE | ~O(N^2) * log(M) | M -> size of the set..
        set<vector<int>> st;

        for(int i=0;i<nums.size();i++){
            //every time i increments, hashset should be empty..
            set<int> hashset;
            for(int j=i+1;j<nums.size();j++){
                //fix the third element..
                int third = -(nums[i]+nums[j]);

                //to check if third element is present in the hashmp..
                if(hashset.find(third)!=hashset.end()){
                    //add pair in the temp vector..
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                //everytime j moves, add that element in the set..
                hashset.insert(nums[j]);
            }
        }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;


    //------------------ Optimest Sol.. ---------------//
    // getting rid of set, by sorting the array beforehand..
    vector<vector<int>> ans;
    //sort the array
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            //as array is sorted, to reduce sum to 0, k needs to move back
            if(sum>0){
                k--;
            }
            //as array is sorted, to increase sum to 0, j needs to move forward
            else if(sum<0){
                j++;
            }
            //if sum==0
            else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]){
                    j++;
                }
                while(j<k && nums[k]==nums[k+1]){
                    k--;
                }
            }
        }
    }
    return ans;
    }
};
