class Solution {
public:
    int countBits(int x){
        int res = 0 ;
        while(x>0){
            if(x%2==1) res+=1;
            x/=2;
        }
        return res;
    }
    int minBitFlips(int start, int goal) {
        return countBits(start^goal);
    }
};