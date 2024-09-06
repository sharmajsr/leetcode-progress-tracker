class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            long long currSpell = spells[i];
            int low = 0 ; 
            int high = m-1;
            int curAns= m;
            while(low<=high){
                // if(low == high){
                //     break;
                // }
                int mid = (low + high) /2;
                long long int currPotion = potions[mid];
                long long prod = currSpell * currPotion;
    
                if(prod >= success){
                    curAns = min (curAns , mid);
                    high =mid-1;
                }else{
                    low = mid+1;
                }
            }
            ans.push_back(m-curAns);

        }
        return ans;
    }
};