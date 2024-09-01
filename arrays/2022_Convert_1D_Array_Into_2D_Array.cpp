//----------- Approach 1 ----------//
//Bruite force 
//TC: O(m*n)
//SC: O(m*n)

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        //initialise the 2d array with the given rows and columns
        vector<vector<int>> ans(m, vector<int>(n));

        //edge case
        if(m*n!=original.size()){
            return {};
        }
        int index = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = original[index];
                index++;
            }
        }
        return ans;
    }
};

//--------- Approach 2 ---------//
//Bruite Force
//TC: O(m*n)
//SC: O(m*n)

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        //initialise the 2d array with the given rows and columns
        vector<vector<int>> ans(m, vector<int>(n));

        //edge case
        if(m*n!=original.size()){
            return {};
        }
        int currentColumn = 0;
        int currentRow = 0;

        for(int i=0;i<original.size();i++){
            //fill the original elements into the ans till column reaches n-1, as range of each row is from 0 to n-1, and post n-1, new row will start
            ans[currentRow][currentColumn] = original[i];
            currentColumn++;
            //starting new row, reinitialised column to 0
            if(currentColumn>n-1){
                currentColumn=0;
                currentRow++;
            }
        }
        return ans;
    }
};

