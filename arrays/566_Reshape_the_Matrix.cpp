class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int current_rows = mat.size();
        int current_columns = mat[0].size();
        
        int total_elements = current_rows * current_columns;
        
        vector<vector<int>> modified_mat(r, vector<int>(c));
        
        int starting_row = 0;
        int starting_column = 0;
        
        if(total_elements == r*c){
            for(int i=0;i<current_rows;i++){
                for(int j=0;j<current_columns;j++){
                    modified_mat[starting_row][starting_column] = mat[i][j];
                    starting_column += 1;
                    //if we reached to the end of a row, then make column as 0, and increment row
                    if(starting_column == c){
                        starting_column = 0;
                        starting_row += 1;
                    }
                }
            }
            return modified_mat;
        }
     return mat;
    }
};
