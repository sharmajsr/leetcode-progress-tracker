class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans = 0, n= a.size() , i = 0,firstTransaction;
        vector<int>leftMaxArray(n,0);
        int mini = a[0];
        int maxi = a[n-1];
        vector<int>rightMaxArray(n,0);
        for(int i = 1 ; i < n ; i++){
            leftMaxArray[i] = max( leftMaxArray[i-1], (a[i]-mini));
            mini = min(mini,a[i]);
        }
        for(int i = n-2 ; i >= 0  ; i--){
            rightMaxArray[i] = max(rightMaxArray[i+1], (maxi-a[i]));
            maxi = max(maxi,a[i]);
        }
        for(int i=0;i<n;i++){
            ans = max(ans, leftMaxArray[i] + rightMaxArray[i]);
        }
        return ans;
    }
};