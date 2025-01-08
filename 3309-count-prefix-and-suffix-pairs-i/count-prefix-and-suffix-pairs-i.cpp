class Solution {
public:
    bool isPrefixAndSuffix(string a,string b){
        int n = a.size(), m = b.size() ,i = 0,j=0,k,l;
        bool isPrefix = true, isSuffix = true;
        while(i<n and j<m and a[i] == b[j]){
            ++i;
            ++j;
        }
        k = n-1 , l = m-1;
        while(k>-1 and l > -1 and a[k] == b[l]){
            --k;
            --l;
        }
        return i == n and k == -1;

    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans= 0 , n =words.size();
        for(int i= 0 ;i<n;i++){
            for(int j=i+1; j <n;j++)
            {
                if(isPrefixAndSuffix(words[i],words[j])) ++ans;
            }
        }
        return ans;
    }
};