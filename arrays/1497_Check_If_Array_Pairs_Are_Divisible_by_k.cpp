
/*
In a pair (a,b) -> if (a+b)%k == 0,
then, (a%k)+(b%k) == k

1%5 --> 1
2%5 --> 2 (not 0)

possible results of x%k are 0, 1, 2, ..., k-1


Step 1: find the reminder of all the elements of the array with k
Step 2: Store the remainders along with their count in a map
Step 3: Transverse the map, and for any element, check if 'k-element' present in the map
Step 4: If yes, check if their frequencies are same.
Step 5: if yes, then they can form a pair, update the count.

Note: no need to check for counter part 
for k=5,
if checked for 1 ---> 4
then skip      4 ---> 1

It works on arrays with negative elements as well

To find the remainder in case of negative elements:
int rem = (num%k + k)%k

-> TC: O(n)
-> SC: O(k) | k -> divisor
*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        //initialising an unordered map
        unordered_map<int, int> mpp;

        //transversing original array, finding remainder and storing them in the set
        for(int i=0;i<arr.size();i++){
            //handling negative remainders
            int remainder = (arr[i]%k + k)%k;
            mpp[remainder]++;
        }

        //handling the case where remainder is 0
        //In this case, count of 0 remainder should be even to form pairs
        if(mpp[0]%2!=0){
            return false;
        }

        //transverse the set and maintain the count of pairs whose sum is k
        for(int remainder=1;remainder<=k/2;remainder++){
            int counterHalf = k - remainder;
            if(mpp[counterHalf]!=mpp[remainder]){
                return false;
            }
        }
    return true;
    }
};
