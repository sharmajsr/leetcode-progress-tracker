class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maxVal= -1 ;
        for(int i= 1 ;i < n-1 ; i++){
            // cout<<i<<" "<<num[i-1]<<" "<<num[i]<<" "<<num[i+1]<<endl;
            if(num[i] == num[i+1] and num[i] == num[i-1] ){
                
                int p = num[i]-'0';
                if(p > maxVal){
                    maxVal = p;
                }
            }
        }
        string temp;
        temp = to_string(maxVal);
        return maxVal == -1 ? "" : temp + temp +temp;
    }
};