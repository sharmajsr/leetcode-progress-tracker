class Solution {
public:
    int solve(vector<int>& piles, int k){
        long long int result = 0;
        for(auto i : piles){
            long long int div = i/k;
            if(i%k == 0 ){
                result += div;
            }
            else{
                result += (div+1);
            }
            
        }
        return result;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int maxElement = LONG_MIN;
        long long int ans = LONG_MAX;
        for(auto i : piles){
            if(i > maxElement)
            maxElement= i;
        }
        // for(int i = 1 ;i <= maxElement ; i++ ){
        //     long long int calculatedHours = solve(piles,i);
        //     if( h >= calculatedHours )
        //         if( ans > i ) ans = i ;
        //         // ans = min(ans,i);

        // }
        int i = 1 ;
        int j = maxElement;
        while(i<=j){
            int mid = ( i+j )/2;
            
            int calculatedHours = solve(piles,mid);
            cout<<i <<" "<<j<<" "<<mid<<" "<<calculatedHours<<endl;
            if( h>= calculatedHours && calculatedHours >0){
                j= mid-1;
                if( ans > mid ) ans = mid ;
            }
            else{
                i = mid+1;
            }
        } 
        return ans;
    }
};