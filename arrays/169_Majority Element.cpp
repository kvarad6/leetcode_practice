//-------------- Approach 1: -----------------------//

//element occurs more than n/2 times -> always occupy middle position
//Sort the array -> find middle element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        return nums[n/2];
    }
};

//---------------- Approach 2 ----------------------//
//Using Hashmap | unordered_map
//TC: O(NlogN)
//SC: O(1)
//fill the occurrence of each element -> transverse & see if for any element, count > n/2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        //record frequency of elements..
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        //check if element occurs more than n/2 times..
        n=n/2;
        for(auto x: mpp){
            if(x.second>n){
                return x.first;
            }
        }
        return 0;
    }
};


//---------------- Approach 3 ----------------------//
//Using Hashmap 
//TC: O(N)
//SC: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = nums[0];

        for(int i=0;i<nums.size();i++){
            if(count==0){
                element = nums[i];
            }

            if(element == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }
};



        //---------------- Approach 4 --------------------//

        //Moore Voting Algorithm -> pending...

    }
};
