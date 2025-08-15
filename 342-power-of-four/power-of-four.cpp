class Solution {
public:
    bool isPowerOfFour(int n) {
        int k =4, i =0 ;
        if( n == 1) return true;
        while( i <= 20 and k <= n){
            if( n == k){
                return true;
            }
            k = k << 2;
            ++i;
        }
        return false;
    }
};
// 4 - 100
// 16 -10000