class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        //start from top right corner..
        int i = 0;
        int j = columns-1;

        while(i<rows && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            //if the current element is greter than target, just skip that entire column, as column elements are arranged in ascending order..
            if(matrix[i][j]>target){
                j--;
            }
            //else if target is greater than current element, skip that entire row as row elements are arranged in ascending order..
            else{
                i++;
            }
        }
        return false;
    }
};
