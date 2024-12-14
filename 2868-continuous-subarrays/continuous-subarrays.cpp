class Solution {
public:
    int maximumFinder(int a,int b){
        return a > b? a:b;
    }
    int minimumFinder(int a,int b){
        return a > b? b:a;
    }
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0  , mini = INT_MAX, maxi = INT_MIN ,i=0,j=0 ,n=nums.size(),numberOfElements;
        while(j<n){
            maxi = maximumFinder(maxi,nums[j]);
            mini = minimumFinder(mini,nums[j]);
            int curDiff = maxi - mini;
            if(curDiff <=2 ){
                ++j;
            }
            else{
                cout<<j <<" "<<i<<endl;
                numberOfElements = j-i ;
                ans += (numberOfElements * (numberOfElements +1 ) * 0.5);
                i=j;
                maxi = nums[j];
                mini = nums[j];
                while(i>=0 and abs(nums[i-1]-nums[j]) <= 2 ){
                    --i;
                    maxi = maximumFinder(maxi,nums[i]);
                    mini = minimumFinder(mini,nums[i]);
                } 
                cout<<"> "<<j<<" "<<i<<endl;
                numberOfElements = (j-i);
                ans -=(numberOfElements * (numberOfElements+1)*0.5);
            }
        }
        numberOfElements = j-i ;
        ans += (numberOfElements * (numberOfElements +1 ) * 0.5);
        return ans;
        
    }
};