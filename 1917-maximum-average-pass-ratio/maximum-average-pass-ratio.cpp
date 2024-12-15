class Solution {
public:
    void heapPush(vector<vector<int>>& classes, int i, priority_queue<pair<double,int>>& maxHeap){
        double curr_avg = (double)classes[i][0]/classes[i][1];
        double new_avg = ((double)classes[i][0]+1)/(classes[i][1] + 1);
        double delta = (double)new_avg-curr_avg;
        // cout<<i<<" "<<curr[i]<<" "<<new_avg[i]<<" "<<delta[i]<<endl;
        maxHeap.push({delta,i});
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double delta_sum=0.0;
        priority_queue<pair<double,int>>maxHeap;
        vector<float>curr(n,0), new_avg(n,0) ,delta(n,0);
        for(int i=0;i<n;i++){
            heapPush(classes,i,maxHeap);
        }
        while(extraStudents--){
            
            auto top = maxHeap.top();
            maxHeap.pop();
            // cout<<top.first<<" "<<top.second<<endl;
            int idx = top.second;

            ++classes[idx][0];
            ++classes[idx][1];

            heapPush(classes,idx,maxHeap);
        }
        for(int i=0;i<n;i++){
            delta_sum += (double)classes[i][0]/classes[i][1];
        }
        return delta_sum/n;
    }
};