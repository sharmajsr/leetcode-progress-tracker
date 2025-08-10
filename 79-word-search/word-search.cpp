class Solution {
public:
    vector<vector<int>> vis;
    bool solve(vector<vector<char>>& board, string word, int r, int c, int idx
               ) {
        if (idx == word.size()) {
            return true;
        }
        vis[r][c] = 1;
        int rows[] = {0, 0, 1, -1};
        int cols[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nr = rows[i] + r;
            int nc = cols[i] + c;
            if (nr >= 0 and nc >= 0 and nr < board.size() and
                nc < board[0].size() and board[nr][nc] == word[idx] and
                vis[nr][nc] !=1 and solve(board, word, nr, nc, idx + 1)) {

                return true;
            }
        }
        vis[r][c] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0]) {
                    cout<<i<<" "<<j<<endl;
                    vis.resize(n, vector<int>(m, 0));
                    if (solve(board, word, i, j, 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
        }
    };