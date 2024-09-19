class Solution {
public:
    bool isPowerOfTwo(int m) {
        if( m == 0 ) return false;
        long long int n = m ;
        long long int ans = n & n-1;
        return ans == 0 ;
    }
};
// 16 - 10000
// 15 - 01111

