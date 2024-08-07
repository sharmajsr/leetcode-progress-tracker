class Solution {
public:
    
    int climbStairs(int n) {
        int s1 =1 , s2 = 2;
        if ( n == 1)    return s1;
        for(int i=2 ; i<n ; i++){
            int temp = s1 + s2;
            s1 = s2;
            s2 =temp;
        }
        return s2;
    }
};