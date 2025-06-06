class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        for(int k=0; k < n; k++){
            vector<int>temp;
            priority_queue<int>maxH;
            for(int i=0;i<n-k;i++){
                // temp.push_back(grid[i+k][i]);
                maxH.push(grid[i+k][i]);
            }
            sort(temp.begin(), temp.end(),greater<int>());
            for(int i=0;i<n-k;i++){
                grid[i+k][i] = maxH.top();
                maxH.pop();
                // temp.pop_front();
            }
        }
        for(int k=1; k < n; k++){
            // vector<int>temp;
            priority_queue<int ,vector<int> , greater<int>>minH;
            for(int i=0;i<n-k;i++){
                // temp.push_back(grid[i][i+k]);
                minH.push(grid[i][i+k]);
            }
            // sort(temp.begin(), temp.end());
            for(int i=0;i<n-k;i++){
                grid[i][i+k] = minH.top();
                minH.pop();
                // temp.pop_front();
            }
        }
        return grid;
        
    }
};

//  00 01 02
//  10 11 12
//  20 21 22