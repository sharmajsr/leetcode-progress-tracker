class Solution {
public:
    bool checkPowersOfThree(int n) {
        int i = 0;
        vector<long>powe;
        while(n != 0){
            int q = n/3;
            int r = n%3;
            if(r==2){
                return false;
            }
            n=q;
        }
        
        return true;
    }
};