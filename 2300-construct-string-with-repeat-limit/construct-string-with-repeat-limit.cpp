class Solution {
public:
    int findNextAvailableCharacter(int cur,vector<int>freq){
        for(int i=cur-1;i>=0;i--){
            if(freq[i] > 0 )    return i;
        }
        return -1;
    }
    string repeatLimitedString(string s, int k) {
        string ans;
        vector<int>freq(26,0);
        for(auto i :s){
            ++freq[i-'a'];
        }
        for(int i=25;i>=0;i--){ while(freq[i] > 0 ){
                for(int j=0;j<k and freq[i] > 0;j++){
                    ans += i+'a';
                    --freq[i];
                }
                if(freq[i]>0){
                    int nxtAvailableCharacterIndex = findNextAvailableCharacter(i,freq);
                    if(nxtAvailableCharacterIndex == -1){
                        return ans;
                    }else{
                        ans += nxtAvailableCharacterIndex+'a';
                        --freq[nxtAvailableCharacterIndex];
                    }
                }
            }
                
            
        }
        return ans;
    }
};