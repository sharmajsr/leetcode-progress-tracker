class Solution {
public:
    int calcFact(int n){
        // cout<<"N : " <<n<<endl;
        if( n <= 1 )    return 1;
        return n * calcFact(n-1);
    }
    string solve(int k ,vector<int>nums){
        if(nums.size() == 0 ){
            return "";
        }
        int prevFact = calcFact(nums.size()-1);
        int q = k / prevFact;
        int r = k % prevFact;
        string temp = to_string(nums[q]);
        nums.erase(nums.begin()+q);
        return temp + solve(r,nums);
    }
    string getPermutation(int n, int k) {
        vector<int>temp;
        for(int i=1;i<=n;i++){
            temp.push_back(i);
            cout<<i<<endl;
        }
        return solve(k-1,temp);
    }
};