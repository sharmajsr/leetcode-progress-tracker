class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0 ,j = 0 , n = nums.size() ,ans = 0 ;
        queue<int>q;
        while(j<n){
            
            if(nums[j] == 1){
                // cout<<"if1 : "<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;
                ans = max(ans, j-i +1);
                ++j;
                // if( j == n ){
                //     ans = max(ans, j-i+1 );
                // }
            }
            else if(nums[j] == 0 and k > 0 ){
                // cout<<"elif1 : "<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;
                ans = max(ans, j-i +1);
                q.push(j);
                --k;
                ++j;
                
            }else if(nums[j] == 0 and k == 0 and q.size() > 0){
                // cout<<"elif2 : "<<i<<" "<<j<<" "<<k<<" "<<ans<<" "<<q.front()<<endl;
                int front = q.front(); q.pop();
                i = front + 1;
                q.push(j);
                ans = max(ans, j-i +1);
                ++j;
            }else{
                // cout<<"elif3 : "<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;
                ++j;
                i=j;
            }
            
        }
        return ans;
        
    }
};
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
// k = 3