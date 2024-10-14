class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<long long>maxHeap;
        for(auto i : nums){
            maxHeap.push(i);
        }
        while(!maxHeap.empty() and k--){
            int top = maxHeap.top();
            maxHeap.pop();
            int q = top/3;
            int rem = top%3;
            if(rem!=0)  q+=1;
            // cout<<top<<" "<<q<<endl;
            ans += top;
            
            maxHeap.push(q);
        }
        return ans;
    }
};