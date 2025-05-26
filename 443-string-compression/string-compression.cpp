class Solution {
public:
    int compress(vector<char>& chars) {
        string temp;
        int n = chars.size();
        for(int i= 0 ; i < n-1 ;i++){
            if(chars[i] == chars[i+1]){
                int k = i ,cnt = 0;
                while(k<n and chars[i] == chars[k]){
                    ++cnt;
                    ++k;
                }
                temp += string()+chars[i] ;
                temp += to_string(cnt);
                i=k-1;
            }else{
                temp += string()+chars[i] ;
                // temp += to_string(1);
            }
        }
        if(chars.size() == 1){
            temp += string() + chars[0];
        }else if(chars[n-1] != chars[n-2]){
            temp += string() + chars[n-1];
        }
        vector<char>ck;
        for(auto i : temp)  ck.push_back(i);
        chars =ck;
        // cout<<"temp : "<< temp<<endl;
        return temp.size();
    }
};