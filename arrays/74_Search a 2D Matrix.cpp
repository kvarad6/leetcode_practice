//---------------- Approach 1 --------------------//
//bruite force..
//transverse entire matrix and check for target
//TC: O(N*M)
//SC: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        int rows = matrix.size();
        int columns = matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};


//---------------- Approach 2 --------------------//
//using binary search (row-wise) | array + binary search
//TC: O(NlogM) | for each row, applying binary search for m elements
//SC: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int columns = matrix[0].size();

        for(int i=0;i<rows;i++){
            int low = 0;
            int high = columns-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(matrix[i][mid]==target){
                    return true;
                }
                else if(matrix[i][mid]<target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

//---------------- Approach 3 --------------------//
// binary search in 2d matrix | matrix + binary search
//TC: O(log(M*N))
//SC: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {    

        int rows = matrix.size();
        int columns = matrix[0].size();

        int low = 0;
        int high = (rows*columns) - 1;

        //can be solved by manually creating indices of imaginary array and use binary serach to find the element.
        // all values are present in 0 -> (m*n-1), if we create a temp array, but consumes extra space..
        //so, need to find mid only using the matrix...
        
        //mid = (row*column-1)

        //To find the indices at mid:
        //row index = mid/column
        //column index = mid%column

        while(low<=high){
            int mid = low + (high-low)/2;
            //if mid element is the target..
            if(matrix[mid/columns][mid%columns]==target){
                return true;
            }

            //if target is greater than mid element, then the target may found in second half..
            if(matrix[mid/columns][mid%columns]<target){
                low = mid+1;
            }
            //else find target in first half..
            else{
                high = mid - 1;
            }
        }
        return false;
     }
};

