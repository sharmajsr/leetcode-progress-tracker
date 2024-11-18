class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n,0);
        int cnt = k;
        for(int i=0 ;i<n ; i++){
            cnt=abs(k);
            if(k>0){
                int j=i+1;
                int sum = 0;
                // cout<<i<<" : "; 
                while(cnt--){
                    j=j%n;
                    // cout<<j<<" , ";
                    sum += code[j];
                    ++j;
                }
                // cout<<" : "<<sum<<endl;
                ans[i] = sum;
            }
            else if(k<0){
                int j=i-1 ;
                int sum = 0 ;
                while(cnt--){
                    if( j == -1 )   j=n-1;
                    sum += code[j] ;
                    --j ;
                }
                ans[i] = sum;
            }
            else if(k == 0 ){
                ans[i] = 0;
            }
        }
        return ans;
    }
};