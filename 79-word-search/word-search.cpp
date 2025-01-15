class Solution {
public:
    vector<vector<int>> vis;
    bool dfs(int p, int q, string word, int idx, vector<vector<char>>& board) {
        vis[p][q] = 1;
        if (idx == word.size()) {
            return true;
        }
        int rows[] = {0, 0, 1, -1};
        int cols[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nrow = rows[i] + p;
            int ncol = cols[i] + q;
            while (nrow >= 0 and nrow < board.size() and ncol >= 0 and
                   ncol < board[0].size() and board[nrow][ncol] == word[idx] and
                   vis[nrow][ncol] == 0 &&
                   dfs(nrow, ncol, word, idx + 1, board)) {
                return true;
            }
        }
    
    vis[p][q] = 0;
    return false;
} bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    vis.resize(n, vector<int>(m, 0));
    bool isFound = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                vis.resize(n, vector<int>(m, 0));
                if (dfs(i, j, word, 1, board))
                    return true;
            }
        }
    }

    return false;
}
}
;