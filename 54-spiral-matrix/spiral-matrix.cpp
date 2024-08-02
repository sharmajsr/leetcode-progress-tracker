class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int top = 0 ;
        int left = 0;
        int bottom = matrix.size()-1;
        int right = matrix[0].size()-1;
        while(top<=bottom && left<=right){
            int f = 0;
            // cout<<"left : "<<left<<" "<<"Right : "<<right<<endl;
            for(int i = left; i<=right ; i++){
                f=1;
                // cout<<top<<" "<<i<<endl;
                ans.push_back(matrix[top][i]);
                // cout<<i<<" " <<matrix[top][i]<<"\n";
            }
            ++top;
            
            for(int i=top;i<=bottom;i++){
                f=1;
                ans.push_back(matrix[i][right]);
                // cout<<matrix[i][right]<<" ";
            }
            --right;
            
            if(top<=bottom){
                for(int i=right; i>=left ;i--){
                    f=1;
                    ans.push_back(matrix[bottom][i]);
                    // cout<<matrix[bottom][i]<<" \n";
                }
                --bottom;
            }
            if(left<=right){
            for(int i= bottom; i>=top ; i--){
                f=1;
                ans.push_back(matrix[i][left]);
                // cout<<matrix[i][left]<<" ";
            }
            ++left;
            }
            // if(!f) break;
        }
        return ans;
    }
};