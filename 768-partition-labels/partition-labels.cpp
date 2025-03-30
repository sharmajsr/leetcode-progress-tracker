class Solution {
public:
    vector<int> partitionLabels(string s) {
        // vector<char>alt,alt1;
        vector<int>ans;
        int start = 0 ;
        unordered_map<char,int>um;
        unordered_map<char,int>temp;
        for(auto i : s) ++um[i];
        for(int i= 0 ; i < s.size() ;i++){
            ++temp[s[i]];
            --um[s[i]];
            bool isValid = true;
            for(auto i : temp){
                if(um[i.first] != 0 ) isValid = false;
            }
            if(isValid){
                ans.push_back(i-start+1);
                start = i+1 ;
                // temp.clear();
            }
        }
        return ans;
    }
};