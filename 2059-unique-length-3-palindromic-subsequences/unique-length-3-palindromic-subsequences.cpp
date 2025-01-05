class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n= s.size();
        unordered_set<string>se;
        vector<int>totalFreq(26,0),leftFreq(26,0);
        for(int i=0;i<n;i++){
            ++totalFreq[s[i]-'a'];
        }
        ++leftFreq[s[0]-'a'];
        for(int i=1;i<n-1;i++){
            for(int j=0;j<26;j++){
                int total = totalFreq[j];
                if(total == 0 ) continue;
                int left = leftFreq[j];
                // if(i==2)    cout<<total<<" "<<left<< " "<<total-left<<endl;
                if(left <= 0 ) continue;
                int right = total - left;
                
                int currIndex = s[i]-'a';
                if( currIndex == j ){
                    --right;
                }
                if(right <= 0 )  continue;
                if(left > 0 and  right >0 ){
                    string temp ;
                    temp += 'a'+j ;
                    temp += 'a'+currIndex;
                    temp +=  'a'+j;
                    // if(temp == "aaa" ) cout<<i<<" " <<j<<" "<<total<<" "<<left<<" "<<right<<endl;  
                    se.insert(temp);
                }
            }
            ++leftFreq[s[i]-'a'];
        }
        // for(auto i :se )    cout<<i<<endl;
        return se.size();
    }
};