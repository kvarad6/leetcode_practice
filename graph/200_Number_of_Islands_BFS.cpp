class Solution {
public:

    void bfs(int row, int column, vector<vector<int>> &visited, vector<vector<char>> &grid) {

        // This block of code checks the following conditions before proceeding with the BFS traversal:

        // The current row and column indices are within the bounds of the grid.
        // The current cell is a land cell ('1').
        // The current cell has not been visited before.
        // If any of these conditions are not met, the function returns without doing anything, effectively skipping the current cell.
        if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || grid[row][column] == '0' || visited[row][column]) {
            return;
        }

        visited[row][column] = 1;
        queue<pair<int, int>> q;
        q.push({row, column});

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            /*
                traversing the neighbours (only horizontally and vertically, not diagonally) 
                need to validate the neighbourRow and neighbourColumn in three steps:
                    1. Validity (should not go out of bound of the grid)
                    2. They have to be land ('1'), not the water
                    3. They should not be visited
            //         */
            for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
                for (int deltaColumn = -1; deltaColumn <= 1; deltaColumn++) {
                    // Skip diagonal neighbors | abs(deltaRow) != abs(deltaColumn)
                    //as problem defination states, adj nodes should be connected horixontally or vertically, not the diagonally to be considered as an island
                    if (abs(deltaRow) != abs(deltaColumn)) {
                        int neighborRow = r + deltaRow;
                        int neighborColumn = c + deltaColumn;
                        if (neighborRow >= 0 && neighborRow < grid.size() && neighborColumn >= 0 && neighborColumn < grid[0].size() && grid[neighborRow][neighborColumn] == '1' && !visited[neighborRow][neighborColumn]) {
                             //if they satisfies above condition, mark them as visited and add them in the queue
                            visited[neighborRow][neighborColumn] = 1;
                            q.push({neighborRow, neighborColumn});
                        }
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        //create a visited array
        int n = grid.size();
        int m = grid[0].size();
        //initialising visited array, initially everything marked as '0'
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for(int row=0;row<n;row++){
            for(int column=0;column<m;column++){
                if(!visited[row][column] && grid[row][column]=='1'){
                    count++;
                    bfs(row, column, visited, grid);
                }
            }
        }
        return count;
    }
};
