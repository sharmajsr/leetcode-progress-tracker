class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size(),i=0;
        // while(i<n-1){
        if(n ==1 )  return false;
        if(n>1 and (arr[0] > arr[1] or arr[n-1] > arr[n-2]))    return false;
        while(i<n-1 and arr[i+1]> arr[i]){
            ++i;
        }
        int j=n-1;
        while(j>=0 and arr[j-1] >arr[j]){
            --j;
        }
        return i==j;
        // }
    }
};