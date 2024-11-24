/*
Approach (based on the observation):
-> If negative numbers -> odd -> make the smallest no. as -ve, and return sum
-> If negative numbers -> even -> convert all -ves into +ves and return sum

Steps:
1. Find overall sum of all the absolute values
2. Count the negative numbers
    2.1 If count is odd -> sum = sum - 2*smallest absolute number
    2.2 If count is even -> sum is the answer

TC: O(n*n)
SC: O(1)
*/
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int countNegatives = 0;
        int smallestAbsolute = INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);

                if(matrix[i][j]<0){
                    countNegatives++;
                }
                smallestAbsolute = min(smallestAbsolute, abs(matrix[i][j]));
            }
        }
        
        if(countNegatives%2==0){
            return sum;
        }
        return sum - 2*smallestAbsolute;
    }
};
