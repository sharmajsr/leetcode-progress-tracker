class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>freq(s.size()+1,0);
        string ans;
        for(auto shift : shifts){
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];
            if( dir == 1){
                ++freq[start];
                --freq[end+1];
            }
            else{
                --freq[start];
                ++freq[end+1];
            }
        }
        for(int i=1;i<s.size();i++){
            freq[i] += freq[i-1];
            freq[i] %= 26;
        }
        for(int i=0 ; i<s.size() ; i++){
            
            long long charInd = s[i]-'a' + freq[i];
            bool negorPos = charInd>=0 ? true: false;
            if(!negorPos)  {
                int q = abs(charInd)/26;
                int newD = q*26 +26;
                charInd += newD;
            }
            int absChar = abs(charInd) ;
            absChar %= 26;
            // cout<<i<<" "<<s[i]<<" "<<charInd<<" "<<freq[i]<<" "<<char(absChar+'a')<<endl;
            ans += char(absChar+'a');
        }
        return ans;

    }
};