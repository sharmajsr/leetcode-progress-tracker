class Solution {
public:
    int countPairs(vector<int>& del) {
        int MOD = 1e9+7;
        // cout<<MOD<<endl;
        int ans = 0;
        unordered_map<int,int>um;
        vector<int>powerOfTwoList ;
        for(int i = 0 ; i <=21 ; i++){
            int powerOfTwo = pow(2,i);
            powerOfTwoList.push_back(powerOfTwo);
        }

        for(auto i :del){
            for(int j=0;j<=21;j++){
                int diff = powerOfTwoList[j] - i ;
                if(um.find(diff) != um.end()){
                    ans = (ans + um[diff]  ) % MOD;
                }
                
            }
            ++um[i];
        }
        return ans;
    }
};

// 4  - 100
// 3  - 011

//      000

// [1,1,1,3,3,3,7]
// 1 - 3 
// 3 - 3 
// 7 -1
// [ 1 , 3 , 7 ]

//  
// 
// 1 
// 3
// 5
// 7
// 9

// [1,3,5,7,9]
//  2,4,8,8,16
//  1 ,1 ,3 ,1, 7
