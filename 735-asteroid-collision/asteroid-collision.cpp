class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(auto i:asteroids){
            if(st.empty()){
                st.push(i);
            }
            else if(st.top()> 0 and i>0 ){
                st.push(i);
            }
            else if(st.top()< 0 and i<0 ){
                st.push(i);
            }
            else if (st.top()<0 && i >0 ){
                st.push(i);
            }else{  //st.top > 0 and i<0
                int  j = -1 *i;
                int flag = false;
                while(!st.empty()){
                    int top = st.top();
                    if(top < 0 ){
                        flag = true;
                        break;
                    }
                    st.pop();
                    if(j < top ){
                        flag = false;
                        st.push(top);
                        break;
                    }
                    else if(j == top){
                        flag = false;
                        break;
                    }
                    else{
                        flag = true;
                    }
                }
                if(flag == true){
                    st.push(i);
                }
            }

        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};