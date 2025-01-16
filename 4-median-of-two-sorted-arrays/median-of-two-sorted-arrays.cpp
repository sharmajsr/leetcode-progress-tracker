class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        for(auto i : nums1) temp.push_back(i);
        for(auto i : nums2) temp.push_back(i);
        sort(temp.begin(),temp.end());
        double ans;
        if(temp.size() & 1){
            ans = temp[temp.size()/2];
        }else{
            int n1 = temp[temp.size()/2];
            int n2 = temp[(temp.size()/2)-1];
            cout<<n1<<" "<<n2<<endl;
            ans = double( (n1+n2) * double(0.5) );
        }
        return ans;
    }
};