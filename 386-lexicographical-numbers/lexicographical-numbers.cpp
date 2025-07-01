class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        unordered_map<char,vector<string>>um;
        for(int i=1 ; i <=n; i++){
            string temp = to_string(i);
            um[temp[0]].push_back(temp);
        }
        for(int i=1;i<=9;i++){
            // cout<<i+'0'<<endl;
            vector<string>temp = um[i+'0'];
            sort(temp.begin(),temp.end());
            for(auto j: temp){
                ans.push_back(stoi(j));
            }
        }

        return ans;
        
    }
};