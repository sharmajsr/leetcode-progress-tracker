class Solution {
public:
    int findNumberOfZeros(string s){
        int zeroCnt= 0;
        for(auto i : s ){
            if( i=='0') ++zeroCnt;
        }
        return zeroCnt;
    }
    int findNumberOfOnes(string s){
        int oneCnt= 0;
        for(auto i : s ){
            if( i!='0') ++oneCnt;
        }
        return oneCnt;
    }
    int maxScore(string s) {
        int maxLen = 0;
        for(int i=1;i<s.size();i++){
            int t1,t2;
            t1 = findNumberOfZeros(s.substr(0,i)) ;
            t2 = findNumberOfOnes(s.substr(i));
            int temp = t1+t2;
            // cout<<s.substr(0,i)<<" "<<t1<<" "<<s.substr(i)<<" "<<t2<<endl;
            
            maxLen =max(maxLen,temp);
        }
        return maxLen;
    }
};