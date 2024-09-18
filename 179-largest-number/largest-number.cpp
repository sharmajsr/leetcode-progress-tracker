class Solution {
public:
    int findOnesDigit(int i ){
        int r;
        while(i>9){
            i/=10;
        }
        return i;
    }
    static bool comp(const string &a , const string &b){
        return (a+b) > (b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>v[10];
        string ans = "";
        for(int i : nums){
            int onesDigitNumber = findOnesDigit(i);
            v[onesDigitNumber].push_back(to_string(i));
        }
        for(int i=9;i >0 ;i--){
            auto ve = v[i];
            sort(ve.begin(),ve.end(),comp);
            // cout<<i<<" : ";
            for(auto j : ve){
                ans += j;
                // cout<<j<<" ";
            }
        }
        if(nums.size() == v[0].size() and v[0].size()>0){
            ans ='0';
        }else if(v[0].size()>0){
            for(int i=0;i<v[0].size();i++){
                ans+="0";
            }
        }
        return ans;
    }
};