class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n,1),freq(n,1);
        int longestLisNum = 0 , maxLis = 1;
        for(int i=1 ;i<n;i++){
            
            for(int j=0; j<i ; j++){
                int lisOfPreviousNumber = lis[j]+1;
                if( nums[i] > nums[j] ){
                    if(lisOfPreviousNumber > lis[i]){

                            lis[i]= lisOfPreviousNumber;
                            freq[i]=freq[j];

                    }else if( lisOfPreviousNumber == lis[i]){
                        freq[i] +=freq[j];
                    }
                } 
                if(lis[i] > maxLis){
                    maxLis = lis[i];
                    longestLisNum = i;
                }

            }
        }
        int ab = 0; 
        for(int i= 0; i< n ;i++){
            if(lis[i] == maxLis)    ab+=freq[i];
        }
        return ab;
    }
};