
class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    // Check row
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == c) return false;
    }
    
    // Check column
    for(int i = 0; i < 9; i++) {
        if(board[i][col] == c) return false;
    }
    
    // Check 3x3 box
    int boxRow = 3 * (row / 3);
    int boxCol = 3 * (col / 3);
    for(int i = boxRow; i < boxRow + 3; i++) {
        for(int j = boxCol; j < boxCol + 3; j++) {
            if(board[i][j] == c) return false;
        }
    }
    return true;
}


    bool solve(vector<vector<char>>& board, int row, int col) {
    // Move to next row if we've reached end of current row
    if(col == 9) return solve(board, row + 1, 0);
    
    // If we've filled all rows, puzzle is solved
    if(row == 9) return true;
    
    // If current cell is already filled, move to next cell
    if(board[row][col] != '.') {
        return solve(board, row, col + 1);
    }
    
    // Try digits 1-9 for empty cell
    for(char c = '1'; c <= '9'; c++) {
        if(isValid(board, row, col, c)) {
            board[row][col] = c;
            if(solve(board, row, col + 1)) return true;
            board[row][col] = '.'; // backtrack
        }
    }
    
    return false;
}
    bool solveSudoku(vector<vector<char>>& board) {
        return solve(board, 0, 0);
    }
};
