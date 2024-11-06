class Solution {
public:
    unordered_map<int,int>um;
    int findSetBits(int n){
        int setBits = 0;
        // while(n> 0 ){
        //     if(n%2 ==0 )    ++setBits;
        //     n/=2;
        // }
        while(n){
            n= n&n-1;
            ++setBits;
        }
        return setBits;
    }
    static bool cmp(int &a1,int &b1){
        int setBits = 0,setBits2 = 0 , a= a1,b =b1;
        while(a> 0 ){
            if(a%2 ==0 )    ++setBits;
            a/=2;
        }
        while(b> 0 ){
            if(b%2 ==0 )    ++setBits2;
            b/=2;
        }
        return  a1<b1 and (setBits == setBits2);
    }
    bool canSortArray(vector<int>& nums) {
        bool canSortArray = true;
        int n= nums.size();
        for(int i=0;i<n-1;i++){
            for(int j = 0 ;j<n-i-1;j++){
                if(nums[j] > nums[j+1]){
                    if( findSetBits(nums[j]) == findSetBits(nums[j+1])){
                        swap(nums[j],nums[j+1]);
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};