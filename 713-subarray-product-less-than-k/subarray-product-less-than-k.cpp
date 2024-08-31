class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        // for(int i=0;i<n;i++){
        //     bool flag = false;
        //     for(int j= i;j<n;j++){
        //         int total = 1 ;
        //         // cout<<i<<" "<<j<<endl;
        //         for(int k=i;k<=j;k++){
        //             // cout<<nums[k]<<" ";
        //             total *= nums[k];
        //         }
                
        //         if(k > total){
        //             // cout<<"total : "<<total;
        //              ++ans;
        //         }else{
        //             flag = true;
        //         } 
        //         // cout<<endl;
            
        //         if(flag == true){
        //             break;
        //         }
        //     }
        // }
        int i= 0 , j=0 , p =1 ;
        while(j<n){
            p = p * nums[j];
            while(i<n and p>=k and i<j){
                p /= nums[i];
                ++i;
            }
            if(k>p) ans += (j-i+1);
            ++j;
        }
        return ans;
    }
};