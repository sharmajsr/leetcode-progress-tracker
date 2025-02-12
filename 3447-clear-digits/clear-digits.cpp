class Solution {
public:
    string clearDigits(string s) {
        int nonDigitCount = 0 ; 
        for(auto i : s){
            if(i>='0' and i<='9')   ++nonDigitCount;
        }
        while(nonDigitCount>0){
            string t = s;
            int n = t.size();
            for(int i=0;i<n;i++){
                if(t[i] >= '0' and t[i] <='9'){
                    if(i>0){
                        --nonDigitCount;
                        t.erase(t.begin()+i);
                        t.erase(t.begin()+i-1);
                        
                    }else{
                        t.erase(t.begin()+i);
                        
                    }
                    break;
                }
            }
            // cout<<nonDigitCount<<" "<<t<<endl;
            s = t;
        }
        return s;
    }
};