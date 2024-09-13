class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>ans;
        vector<int> xo(n,0);
        xo[0]=arr[0];
        for(int i=1;i<n;i++){
            xo[i] = arr[i]^xo[i-1];
        }
        for(auto i : queries){
            int temp;
            
            if(i[0] != 0 )  temp = xo[i[1]]^xo[i[0]-1];
            else    temp = xo[i[1]];
            
            ans.push_back(temp);
        }
        return ans;
    }
};