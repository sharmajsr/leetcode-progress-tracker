class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string>ans;
        for(int i=0 ; i<n ; i+=k){
            string temp = s.substr(i,k);
            if(temp.size()  <k ){
                int fill_cnt = (k-temp.size());
                while(fill_cnt--){  temp += fill; }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};