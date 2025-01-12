class Solution {
private:
    bool inBoard(vector<vector<char>>& board, int i, int j, int m, int n) {
        if(i>0 && j>0 && i<m && j<n) {
            return true;
        }
        return false;
    }
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        board[i][j] = ' ';
        if(inBoard(board, i-1, j, m, n) && board[i-1][j] == 'O')
            dfs(board, i-1, j, m, n);
        if(inBoard(board, i+1, j, m, n) && board[i+1][j] == 'O')
            dfs(board, i+1, j, m, n);
        if(inBoard(board, i, j-1, m, n) && board[i][j-1] == 'O')
            dfs(board, i, j-1, m, n);
        if(inBoard(board, i, j+1, m, n) && board[i][j+1] == 'O')
            dfs(board, i, j+1, m, n);
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> edgeRow{0, m-1};
        vector<int> edgeCol{0, n-1};

        // Call DFS on top and bottom edges
        // mark all O as ' '
        for(int i:edgeRow) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O') {
                    dfs(board, i, j, m, n);
                }
            }
        }
        // Call DFS on left and right edges
        // mark all O as ' '
        for(int j:edgeCol) {
            for(int i=0; i<m; i++) {
                if(board[i][j] == 'O') {
                    dfs(board, i, j, m, n);
                }
            }
        }
        // Finally go thru the whole matrix
        // Set all remaining 'O's to 'X' and
        // revert all ' ' back to 'O'
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O') {
                    if(board[i-1][j] == 'X' || board[i][j-1] == 'X' ||
                        board[i+1][j] == 'X' || board[i][j+1] == 'X') {
                            board[i][j] = 'X';
                    }
                } else if(board[i][j] == ' ') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
