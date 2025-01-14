class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long tsum = 0 , i= 1,j, min_ans = INT_MAX;
        for(auto banana : piles ) tsum += banana;
        j= tsum;
        while(i<=j){
            long long mid = (i+j)/2;
            int k= 0 , temp=0;
            for(auto l : piles){
                long long q = l/mid;
                long long r = l%mid;
                if(r>0) ++q;
                temp+=q;
            }
           
            if( temp <= h ){
                min_ans = min(min_ans,mid);
                j = mid-1;
            }else if(temp > h){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
            // cout<<i<<" "<<mid<<" "<<j<<" "<<min_ans<<endl;
        }
        return min_ans;
    }
};