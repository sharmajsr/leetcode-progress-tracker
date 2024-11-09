class Solution {
    #define ll long long
    vector<int> getBin(int n){
        vector<int> res;
        while(n){
            if(n&1)     res.push_back(1);
            else        res.push_back(0);
            n>>=1;
        }
        return res;
    }
public:
    long long minEnd(int n, int x) {
        if(n==1)    return x;

        //Step-1: Record zero positions
        vector<int> zero_pos;
        int count=0;
        int val = x;
        while(val){
            if((val&1) == 0)
                zero_pos.push_back(count);
            count++;
            val>>=1;
        }

        //Step-2: Find no of bits required to make N combinations
        int reqd_bits = ceil(log2(n));

        //Step-3: Append more bits in zero_pos as per requirement
        for(int i=zero_pos.size();i<reqd_bits;++i)
            zero_pos.push_back(count++);
        
        //Step-4: Find bits to be appended
        vector<int> append_bits = getBin(n-1);

        //Step-5: Form the answer
        ll ans = x;
        int pos = append_bits.size();
        while(pos--){
            if(append_bits.back()==1)
                ans += pow(2,zero_pos[pos]) * append_bits[pos];
        }
        return ans;
    }
};