class Solution {
public:
    bool isBlack(int x,int y){
        if( x%2 == 0){
            if(y%2 == 1){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(y%2 == 1){
                return false;
            }
            else{
                return true;
            }
        }
    }
    bool checkTwoChessboards(string co1, string co2) {
        int c11 = co1[0]-'a'+1;
        int c12 = co1[1];
        int val1 = isBlack(c11,c12);
        int c21 = co2[0]-'a'+1;
        int c22 = co2[1];
        int val2 = isBlack(c21,c22);
        return val1 == val2;
        
    }
};

