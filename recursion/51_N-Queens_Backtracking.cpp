class Solution {
public:
    vector<vector<string>> result;
    int N;

    //Function to check if position is valid to place queen
    bool isValid(vector<string>& board, int row, int column){

        //look upward 
        for(int i=row-1; i>=0;i--){
            if(board[i][column]=='Q'){
                return false;
            }
        }

        //look diagonally left upwards
        //[both i, j are involved as column is also gonna change]
        for(int i=row-1, j=column-1; i>=0 && j>=0; i--, j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //look diagonally right upwards
        for(int i=row-1, j=column+1; i>=0 && j<N; i--, j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        return true;
    }


    void solve(vector<string>& board, int row){
        if(row == N){
            result.push_back(board);
            return;
        }

        //Started placing the queen from 0th column
        for(int col=0; col<N; col++){
            if(isValid(board, row, col)){
                //if the current position is valid, place the queen
                board[row][col] = 'Q';
                solve(board, row+1);
                board[row][col] = '.'; //backtrack & check next columns 
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.')); 
        //n=3 -> {..., ..., ...} 
        solve(board, 0); //0 -> row
        return result;
    }
};
