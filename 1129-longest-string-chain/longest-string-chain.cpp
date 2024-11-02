class Solution {
public:
    static bool cmp1(string &a,string &b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp1);
        int n = words.size() ,ans = 0 ;
        unordered_map<string,int>lis;
        for(string word: words){
            cout<<word<< " : ";
            for(int j=0;j<word.size();j++){
                
                string nWord = word;//.substr(0,j)+word.substr(j+1);
                
                nWord.erase(nWord.begin()+j);
                lis[word] = max(lis[nWord]+1,lis[word]);
                // cout<<nWord<<" , "<<lis[word]<<endl;

            }
            ans = max(ans,lis[word]);
        }
        // for(int i=0;i<n;i++)    cout<<words[i]<<" "<<lis[words[i]]<<endl;
        return ans;
    }
};