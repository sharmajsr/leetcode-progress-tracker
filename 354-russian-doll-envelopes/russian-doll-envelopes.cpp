class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int>lis;
        sort(envelopes.begin(),envelopes.end(),cmp);
        lis.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            int ele = envelopes[i][1];
            int ind = lower_bound(lis.begin(),lis.end(),ele) - lis.begin();
            if(ind >= lis.size())    lis.push_back(ele);
            else    lis[ind] = ele;
        }
        return lis.size();
        
    }
};