class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n=s.size();
        int curMaxIndex = n-1;
        vector<int>rMaxIndex(n,0);
        for(int i=n-1;i>=0;i--){
            if(s[i] > s[curMaxIndex]){
                curMaxIndex = i;
            }
            rMaxIndex[i] = curMaxIndex;
        }
        
        for(int i=0;i<n;i++){
            if(s[i] < s[rMaxIndex[i]]){
                swap(s[i],s[rMaxIndex[i]]);
                break;
            }
        }
        int ans = stoi(s);
        return ans;
    }
};

