class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;
        vector<int> ans;
        while (top <= bottom and left <= right) {
            for (int i = left; i <= right; i++) {
                // cout << "right : " << matrix[top][i] << endl;
                ans.push_back(matrix[top][i]);
            }
            ++top;
            for (int i = top; i <= bottom; i++) {
                // cout << "bottom : " << matrix[i][right] << endl;
                ans.push_back(matrix[i][right]);
            }
            --right;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    // cout << "left : " << matrix[bottom][i] << endl;
                    ans.push_back(matrix[bottom][i]);
                }

                --bottom;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    // cout << "top : " << matrix[i][left] << endl;
                    ans.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return ans;
    }
};