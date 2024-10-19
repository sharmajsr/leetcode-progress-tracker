class Solution {
public:
    char findKthBit(int n, int k) {
        vector<string>v;
        v.push_back("0");
        for(int i=1;i<=20;i++){
            string prev = v[i-1];
            string newString = prev + '1';
            reverse(prev.begin(),prev.end());
            for(auto i : prev){
                if(i=='1') newString+='0';
                else    newString +='1';
            }
            // cout<<newString<<endl;
            v.push_back(newString);
        }

        

        return v[n-1][k-1];
    }
};