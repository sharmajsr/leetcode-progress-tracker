class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>um;
        vector<string>ans;
        int n1 = s1.size() , n2 = s2.size() ,start=0;
        for(int i=0;i<n1;i++){
            cout<<i<<" "<<s1[i]<<endl;
            if( s1[i] == ' ' ){
                string s = s1.substr(start,i-start);
                ++um[s];
                start = i+1;
            }
        }
        string s = s1.substr(start,s1.size()-start);
        ++um[s];
        start=0;
        for(int i=0;i<s2.size();i++){
            if( s2[i] == ' ' ){
                string s = s2.substr(start,i-start);
                ++um[s];
                start = i+1;
            }
        }
        s = s2.substr(start,s2.size()-start);
        ++um[s];
        for(auto i : um){
            if(i.second ==1 )
            ans.push_back(i.first);
        }
        return ans;
    }
};