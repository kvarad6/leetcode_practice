// User function Template for C++

//bruite force thinking-> finding even/odd -> fill out the array
// if digit is even -> 0, 2, 4,..., n-1 positions to fill
// if digit is odd -> 1, 3, 5,..., n positions to fill

// Approach 1: 
//TC: O(2N)
//SC: O(2N)

class Solution {
  public:
    void reArrange(int arr[], int N) {
        //transverse original array to seperate out evens and odds in two seperate arrays
        vector<int> evens;
        vector<int> odds;
        
        for(int i=0;i<N;i++){
            if(arr[i]%2==0){
                evens.push_back(arr[i]);
            }else{
                odds.push_back(arr[i]);
            }
        }
        int evenIndex = 0, oddIndex = 0;
        
        //build the final array
        for(int i=0;i<N;i++){
            if(i%2==0){
                // Even index should have even number
                arr[i] = evens[evenIndex++];
            }else{
                arr[i] = odds[oddIndex++];
            }
        }
        
    }
};
