class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
        the direction would be: right -> bottom -> left -> top
        top-most row -> 0
        bottom-most row -> m-1
        left-most -> 0
        right-most -> n-1

        first we are going from left -> right 
        for(i = left -> right) a[top][i] 

        when we reach i==right, top becomes top+1
        top++

        for(i=top->bottom) a[i][right] 

        when we reach i==bottom, right becomes right-1
        right--

        for(i=right->left) a[bottom][i]

        when we reach i==left, bottom becomes bottom-1
        bottom--

        for(i=bottom->top) a[i][left]

        one circle of spiral completes here

        overall, 
        if left<right -> there are columns pending that need to be spiriled
        if top<bottom -> there are rows pending that need to be spiriled
        */ 

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        //initialising left, right, top and bottom
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;

        while(top<=bottom && left<=right){
            //right 
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //bottom
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            //handling the case -> if there is only one row -> left will not be printed
            if(top<=bottom){
                //left
                for(int i=right; i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                //top
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
