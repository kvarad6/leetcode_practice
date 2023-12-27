//---------------- Approach 1 | Bruite Force -----------------//
//TC: O(N*M)*(N+M)
//SC: O(1)

class Solution {
public:
    void markRow(int i, int rows, int columns, vector<vector<int>>& matrix){
        for(int j=0;j<columns;j++){
            if(matrix[i][j]!=0){
                matrix[i][j] = -999;
            }
        }
    }

    void markColumn(int j, int rows, int columns, vector<vector<int>>& matrix){
        for(int i=0;i<rows;i++){
            if(matrix[i][j]!=0){
                matrix[i][j] = -999;
            }
        }
    }


    void setZeroes(vector<vector<int>>& matrix) {
        //bruite force
        //identifying poistion where '0' is present -> marking ith row and column '-1'
        //whereever there is '-1', mark it as '0'.
        int rows = matrix.size();
        int columns = matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(matrix[i][j]==0){
                    markRow(i, rows, columns, matrix);
                    markColumn(j, rows, columns, matrix);
                }
            }
        }

        //marking all '-1's to '0's by transversing matrix

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(matrix[i][j]==-999){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//---------------- Approach 2 | Optimal --------------------//
//Using extra dummy row/column
//TC: O(N*M + N*M)
//SC: O(N) + O(M)

class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int columns = matrix[0].size();

        vector<int> dummyRow(rows, 1);
        vector<int> dummyColumn(columns, 1);

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(matrix[i][j]==0){
                    dummyRow[i] = 0;
                    dummyColumn[j] = 0;
                }
            }
        }

        //making corresponding row/column element as '0'
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(dummyRow[i]==0 || dummyColumn[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//-------------- Approach 3 | Optimised Way ----------------//
//To reduce space complexity from O(M) + o(N) (dummy row/column) to O(1) (inplace)


