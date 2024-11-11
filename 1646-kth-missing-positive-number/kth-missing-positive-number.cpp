class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>a(3000,0);
        for(auto i : arr)   ++a[i];
        for(int i=0 ; i < 3000 ; i++){
            if(a[i] == 0)   --k;
            if(k==-1)  return i;
        }
        return -1;
    }
};