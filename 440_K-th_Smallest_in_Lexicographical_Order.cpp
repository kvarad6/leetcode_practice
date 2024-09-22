//----------- Approach 1 ----------//
/*
Step 1: Store the elements from 1-n in the string vector
Step 2: Sort the string vector (in ascending order)
Step 3: return the element present at k-1th index

-> Gives TLE
*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        vector<string> elements;
        for(int i=1; i<=n; i++){
            elements.push_back(to_string(i));
        }

        sort(elements.begin(), elements.end());

        return stoi(elements[k-1]);
    }
};

//--------- Approach 2 ----------//
/*
-> Starting from the prefix 1, we need to observe the 'k' and learn to skip the prefixes that will not give us the expected kth element
-> e.g: n=22 & k=14, when we start with the prefix 1 (1, 10, 11, ..., 19) we'll not get the 14th index in 1, so instead of calculating prefixes start with 1, we could skip them and can directly jump to prefixes starting with 2
-> In this way, we can reduce the TC from O(n) to something lesser.
-> Need to check if the element is in the limit or not along the way
-> to calculate how many numbers are there in level 1 (between 1 and 2), we substracted 1 from 2 -> 1 number,
    now, to calculate numbers in level 2 (how many prefixes are there in level 2 (between 1 and 2)),
    multiply 1 with 10 -> 10
    multiply 2 with 10 -> 20
    20-10 -> 10 numbers starting with 1 are there (10, 11, ... , 19)

    So, till level 2, we got 1+10 -> 11 numbers/ prefixes starting from 1 
*/

class Solution {
public:
    //function to calculate total prefix that can be formed under curr
    int Count(long curr, long next, int n){
        int countNum = 0;
        //checking if the element is in the bound/ range 1-n
        while(curr<=n){
            //first level : 1-2
            //countNum -> 2-1 -> 1
            countNum += (next-curr);

            //going down to next level (level 2),
            //countNum -> 20-10 -> 10
            next *= 10;
            curr *= 10;

            //As next should not exceed the limit (n)
            next = min(next, long(n+1));
        }
        return countNum;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k-1;

        while(k>0){
            int count = Count(curr, curr+1, n);
            //in that perticular level, if no. of prefixes are lesser than the index we need to access, then skip that prefixes starting with perticular number, and go to next one
            if(count<=k){
                curr++;
                k -= count; //skipping those prefixes
            }else{
                //if desired index is lesser than the prefix count, go to the one level deep, and reduce the k by 1 as we have covered current level element
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};
