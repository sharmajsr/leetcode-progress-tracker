class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_capacity = 0 , min_capacity=0,ans= 0;
        for(auto i : weights){
            max_capacity +=i;
            min_capacity = max(min_capacity , i);
        }
        while(min_capacity < max_capacity){
            int mid = (min_capacity + (max_capacity-min_capacity)/2);
            int sum = 0, maxSum =0 ;
            int day =1;
            for(auto weight : weights){
                if(sum+weight>mid){
                    sum=0;
                    ++day;
                }
                sum += weight;
            }
            // ans = mid;

            if(days < day)  min_capacity = mid +1;
            else max_capacity = mid;

        }
        return min_capacity;
    }
};
