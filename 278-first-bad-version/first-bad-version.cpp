// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1 , high = n ,ans = n;
        while(low<=high){
            int mid = low + (high-mid)/2;
            bool check = isBadVersion(mid);
            if(check){
                ans = min(ans,mid);
                high =mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};