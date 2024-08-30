class Solution {
public:
    struct cell{
        int row;
        int col;
        int height;
    };
    struct compareHeight{
        bool operator()(const cell& a, const cell& b){
            return a.height > b.height;
        }
    };
    int trapRainWater(vector<vector<int>>& height) {
        priority_queue<cell , vector<cell>,compareHeight >minHeap;
        int ans = 0 ; 
        int rows[] = {0 , 1 , 0 , -1};
        int cols[] = {1 , 0 , -1, 0 };
    
        int n = height.size() , m = height[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( i==0 || j == 0 || i == n-1 || j == m-1){
                    // cout<<i <<" "<<j<<endl;
                    vis[i][j] =1;
                    cell ce ;
                    ce.row = i;
                    ce.col = j;
                    ce.height = height[i][j];
                    minHeap.push(ce);
                }
            }
        }
    
        while(!minHeap.empty()){
            auto it = minHeap.top();
            cout<<it.row<<" "<<it.col<<" "<<it.height<<endl;
            minHeap.pop();
            for(int i=0;i<4;i++){
                
                int nRow =  it.row + rows[i];
                int nCol = it.col + cols[i];
                if( nRow >=0 && nRow < n && 
                nCol >= 0 && nCol < m  &&
                vis[nRow][nCol] == 0 
                ){
                    cout<<it.row<<" "<<it.col<<" "<<it.height<<" "<<nRow<<" "<<nCol<<" "<<height[nRow][nCol]<< endl;
                    vis[nRow][nCol] = 1; 
                    if(height[nRow][nCol] > it.height){
                        minHeap.push({nRow,nCol,height[nRow][nCol]});
                    }
                    if(height[nRow][nCol] < it.height){
                        ans += ( it.height - height[nRow][nCol]);
                        minHeap.push({nRow,nCol,it.height});
                    }
                    else if(height[nRow][nCol] ==  it.height){
                        minHeap.push({nRow,nCol,it.height});
                    }
                }
            }
        }
        return ans;
    }
};