class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0 , right = arr.size()-1;
        while(left<right){
            int mid = (left + right)/2;
            // if(mid == 0 or mid =)
            if(  arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]){  //mid != 0
                return mid;
            }else if(arr[mid-1] < arr[mid] and arr[mid] < arr[mid+1]){
                left =mid+1;
            }else{
                right =mid;
            }
        }
        return 1;
    }
};