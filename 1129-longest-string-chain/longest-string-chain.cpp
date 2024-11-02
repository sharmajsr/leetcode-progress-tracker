class Solution {
public:
    static bool cmp1(string &a,string &b){
        return a.size() < b.size();
    }
    bool comp(string st1,string st2){
        string s1,s2;
        if(st1.size() > st2.size()){
            s1 = st1;
            s2 = st2;
        }else{
            s1 = st2;
            s2 = st1;
        }
        int n = s1.size() , m = s2.size(),i=0,j=0;
        if(abs(n-m) != 1)       return false;
        while(i < n and j < m ){
            if(s1[i] == s2[j]){
                ++i;++j;
            }
            else{
                ++i;
            }
        }
        if( j == m and i== n-1) return true;
        if( i == n and j==m) return true;
        return false;

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
                cout<<nWord<<" , "<<lis[word]<<endl;

            }
            // cout<<endl;
            ans = max(ans,lis[word]);
        }
        for(int i=0;i<n;i++)    cout<<words[i]<<" "<<lis[words[i]]<<endl;
        return ans;
    }
};