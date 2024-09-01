class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m*n != r*c){
            return mat;
        }

        vector<vector<int>> ans(r, vector<int>(c));
        int currentRow = 0;
        int currentColumn = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[currentRow][currentColumn] = mat[i][j];
                currentColumn++;
                //if we reached to the end of a row, then make column as 0, and increment row
                if(currentColumn==c){
                    currentColumn=0;
                    currentRow++;
                }
            }
        }
        return ans;
    }
};
