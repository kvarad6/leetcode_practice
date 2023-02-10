class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int length = matrix.size();

        //Matrix transpose..
        for(int i=0;i<length;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //Reverse every row
        for(int i=0;i<length;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
       
    }
};
