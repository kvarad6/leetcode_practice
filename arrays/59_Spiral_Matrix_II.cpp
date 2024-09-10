class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //initialise a matrix
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int left = 0, right = n-1;
        int top = 0, bottom = n-1;
        //declaring a num variable, will increment it on the go
        int num = 1;

        while(top<=bottom && left<=right){
            //towards right
            for(int i=left;i<=right;i++){
                matrix[top][i] = num++;
            }
            top++;

            //towards bottom 
            for(int i=top; i<=bottom; i++){
                matrix[i][right] = num++;
            }
            right--;

            //towards left
            for(int i=right; i>=left; i--){
                matrix[bottom][i] = num++;
            }
            bottom--;

            //towards top
            for(int i=bottom; i>=top; i--){
                matrix[i][left] = num++;
            }
            left++;
        }
        return matrix;
    }
};
