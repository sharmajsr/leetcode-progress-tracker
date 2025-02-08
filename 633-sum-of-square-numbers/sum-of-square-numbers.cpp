class Solution {
public:
    bool judgeSquareSum(int c) {
        long long k = 0; 
        vector<int>squares;
        unordered_map<int,int>um;
        while(true){
            if( (k*k) > INT_MAX){
                break;
            }
            long long temp = k * k ; 
            squares.push_back(temp);
            ++um[temp];
            ++k;
        }

        for(int i=0;i<squares.size();i++){
            int diff = c - squares[i];
            if(diff < 0 ) return false;
            if( um.find(diff) != um.end() ){
                return true;
            }
        }
        return false;
    }
};