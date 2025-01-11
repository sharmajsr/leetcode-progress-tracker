class Solution {
public:
    bool canConstruct(string s, int k) {
        int oddCount = 0 ;
        if(k>s.size() ){
            return false;
        }
        vector<int>freq(26,0);
        for(auto i : s){
            ++freq[i-'a'];
        }
        for(int i=0;i<26;i++){
            if(freq[i] %2 ==1  ) ++oddCount;
        }
        if(oddCount > k ) return false;
        return true;
    }
};