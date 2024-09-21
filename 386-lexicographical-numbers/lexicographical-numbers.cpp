class Solution {
public:
    static bool comp(const string &a,const string &b){
        return a+b > b+a;
    }
    int firstChar(int i){
        while(i>9)  i/=10;
        return i;
    }
    // 1123
    int convertStringToNum(string s){
        int ans = 0;
        for(auto i : s){
            ans = ans*10 + i-'0';
        }
        return ans;
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        vector<string>numbers[10];
        for(int i=1;i<=n;i++){
            string temp = to_string(i);
            // cout<< i << " "<<temp<<" "<<temp.substr(0,1)<<endl;
            int firstNum = firstChar(i);
            numbers[firstNum].push_back(temp);
        }
        
        for(int i=1;i<=9;i++){
            vector<string>v = numbers[i];
            sort(v.begin(),v.end());
            for(auto num: v){
                int numi = convertStringToNum(num);
                ans.push_back(numi);
            }
        }
        return ans;
    }
};