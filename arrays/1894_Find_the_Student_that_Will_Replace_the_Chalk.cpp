//---------- Approach 1 ------------//
// TLE | 71/72 testcases passed
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int noOfStudents = chalk.size();
        int index = 0;
        while(k>0){
            k -= chalk[index];
            if(k<0){
                return index;
            }
            if(index==noOfStudents-1){
                index=0;
            }else{
                index++;
            }
        }
        return 0;
    }
};

//----------- Approach 2 -----------//
// Optimised | Using Modulus
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int noOfStudents = chalk.size();
        int index = 0;
        long long totalChalks = 0;
        for(int i=0;i<chalk.size();i++){
            totalChalks += chalk[i];
        }
        /*
        -> To ensures that k is always within the range of the total chalk piece
        -> By taking the modulus (%) of k with totalChalk, we're extracting this relevant part of k that represents the number of chalk pieces left to be distributed in the current cycle.
        For e.g:
        totalChalk = 10 (sum of all the elements present in the chalks array)
        k = 25
        so after the first cycle, 15 chalks left.
        after the second cycle, 5 chalks left.
        so for the third cycle, we only need to deal with 5 chalks.
        we can directly jump to the last cycle by skipping the intermediate cycles, and get the chalks to deal with, in the last cycle using the modules (remainder)
        */
        k = k%totalChalks;

        for(int i=0;i<noOfStudents;i++){
            k -= chalk[i];
            if(k<0){
                return i;
            }
        }
        return 0;
    }
};
