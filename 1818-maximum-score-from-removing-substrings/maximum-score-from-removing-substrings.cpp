class Solution {
public:
    int solve(string& s, int x, int y,char a, char b) {
        int n = s.size();
        int answer = 0;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty() or s[i] !=  b) {
                st.push(s[i]);
            } else if (!st.empty() and s[i] == b) {
                if (st.top() == a) {
                    st.pop();
                    answer += x;
                } else {
                    st.push(s[i]);
                }
            }
        }
        string temp;
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++) {
            // check for ba first
            if (st.empty() or temp[i] != a) {
                st.push(temp[i]);
            } else if (!st.empty() and temp[i] == a) {
                if (st.top() == b) {
                    st.pop();
                    answer += y;
                } else {
                    st.push(temp[i]);
                }
            }
        }

            return answer;
        }

        int maximumGain(string s, int x, int y) { 
            if(x > y ){
                return solve(s,x,y,'a','b');
            }
            return solve(s, y,x,'b','a');
            
        }
    };
