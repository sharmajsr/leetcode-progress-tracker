class Solution {
public:
    bool isASubstring(string a ,string b){
        // if(b.size()<a.size()){  
        //     string temp = b;
        //     b = a;
        //     a = temp;
        // }

        int n=a.size(), m = b.size() ,i = 0 , j = 0;

        bool isSubstring = false;
        while(i<n){
            j=0;
            if(a[i] == b[j]){
                int k = i , l=j;
                while(k<n and l<m and a[k] == b[l]){
                    ++k;
                    ++l;
                }
                // cout<<
                if(l == m){
                    return true;
                }
            }
            ++i;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        set<string>se;
        sort(words.begin(),words.end(),greater<string>());
        unordered_map<string,int>um;
        int n= words.size();
        for(int i=0;i<n;i++){
            cout<<words[i]<<endl;
            for(int j=i+1;j<n ;j++){
                string a,b;
                a = words[i]; // chota hoga
                b = words[j];
                if(b.size() < a.size()){
                    string temp = a;
                    a=b;
                    b = temp;
                }
                bool isSubstringTrue = isASubstring(b,a);
                // cout<<a<<" "<<b<<" "<<isSubstringTrue<<endl;
                if(isSubstringTrue){
                    
                    // if(words[i].size() > words[j].size()) {
                    // cout<<"if : "<<words[i]<<" "<<words[j]<<endl;
                    se.insert(a);
                        // ans.push_back(a);
                    // }else {
                    //     ans.push_back(words[i]);
                    // }
                }
            }
        }
        for(auto i : se){
            ans.push_back(i);
        }
        return ans;
    }
};