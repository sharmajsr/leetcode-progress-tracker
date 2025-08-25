// dekho ideally isme we dont have to push the char with its freq, what matters to us is only freq.
// as given take out first n+1 element from help and push it to a vector, also add heap not empty condition
// push vector in push , only if freq-1 > 0
// if heap is not empty, means current element k liye apna (n+1) zaoorat pada tha
// else added temp vector size to ans, since it is the last
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if ( n == 0 )   return tasks.size();
        int k = n , ans= 0 ;
        unordered_map<int,int>um;

        priority_queue<pair<int,int>>maxH;

        for(auto i : tasks){
            ++um[i-'a'];
        }
        for(auto i : um){
            maxH.push({i.second,i.first});
        }
        while(!maxH.empty()){
            vector<pair<int,int>>temp;
            for(int i = 0 ; i <= n ;i++){
                if(!maxH.empty()){
                    auto top = maxH.top();
                    maxH.pop();
                    temp.push_back(top);
                }
            }
            for(auto i : temp){
                if(i.first-1 > 0)
                maxH.push({i.first-1,i.second});
            }

            if(!maxH.empty()){
                ans += (n+1);
            }else{
                ans += temp.size();
            }
        }
        return ans;
    }
};

// A - 3 , B - 3 
// ["A","C","A","B","D","B"]
// A -2  , C - 1, B - 2, D -1
// A -2, B -2 , C - 1 , D - 1

