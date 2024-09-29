class Solution {
public:
    int m, n;
    //initialising a direction vector
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    //function where we are going in all possible directions, searching the word, backtracking if not found
    bool findWord(vector<vector<char>>& board, int i, int j, int idx, string& word){
        //if we reach to the end of the word, return true
        if(idx==word.size()){
            return true;
        }
        //else, check the basic conditions that should not be true
        //'$' indicates visited path
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$'){
            return false;
        }

        if(board[i][j]!=word[idx]){
            return false;
        }
        //storing the current element in temp and marking it as visited
        char temp = board[i][j];
        board[i][j] = '$';

        for(auto dir: directions){
            int i_ = i+dir[0];
            int j_ = j+dir[1];

            if(findWord(board, i_, j_, idx+1, word)){
                return true;
            }
        }
        //resetting the element if word has not found along this path
        board[i][j] = temp;
        return false;
    }

    //passing word as a reference to reduce unnessasary copies
    bool exist(vector<vector<char>>& board, string& word) {
        m = board.size();
        n = board[0].size();

        //early termination
        //We check if the board has enough characters to form the word before starting the search.
        if(m*n<word.length()){
            return false;
        }

         // Count character frequencies
         //We count the frequency of characters in both the word and the board. If the board doesn't have enough of any character needed for the word, we return false early.
        vector<int> wordCount(128, 0), boardCount(128, 0);
        for (char c : word) wordCount[c]++;
        for (const auto& row : board)
            for (char c : row) boardCount[c]++;

        // Check if the board has enough of each character
        for (char c : word)
            if (wordCount[c] > boardCount[c]) return false;

        // Start search from less frequent character
        //We compare the frequency of the first and last character of the word. If the last character is less frequent, we reverse the word to start our search from the less common character, potentially reducing the number of paths to explore.
        if (wordCount[word[0]] > wordCount[word.back()]) {
            reverse(word.begin(), word.end());
        }

        //traversing the grid and find the word
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && findWord(board, i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
