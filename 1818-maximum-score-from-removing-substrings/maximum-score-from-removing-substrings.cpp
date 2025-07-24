class Solution {
public:
    int solve(string& s, int x, int y) {
        int n = s.size();
        int answer = 0;
        stack<char> st;
        if (x > y) {
            for (int i = 0; i < s.size(); i++) {
                // check for ab first
                if (st.empty() or s[i] != 'b') {
                    st.push(s[i]);
                } else if (!st.empty() and s[i] == 'b') {
                    if (st.top() == 'a') {
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
                if (st.empty() or temp[i] != 'a') {
                    st.push(temp[i]);
                } else if (!st.empty() and temp[i] == 'a') {
                    if (st.top() == 'b') {
                        st.pop();
                        answer += y;
                    } else {
                        st.push(temp[i]);
                    }
                }
            }
        } else {
            for (int i = 0; i < s.size(); i++) {
                // check for ba first
                if (st.empty() or s[i] != 'a') {
                    st.push(s[i]);
                } else if (!st.empty() and s[i] == 'a') {
                    if (st.top() == 'b') {
                        st.pop();
                        answer += y;
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
                if (st.empty() or temp[i] != 'b') {
                    st.push(temp[i]);
                } else if (!st.empty() and temp[i] == 'b') {
                    if (st.top() == 'a') {
                        st.pop();
                        answer += x;
                    } else {
                        st.push(temp[i]);
                    }
                }
            }
        }
        return answer;
    }

    int maximumGain(string s, int x, int y) {
       
        return solve(s,x,y);
    }
};

// point = 0
// cdbcbbaaab
// cdbcbaab + 5
// cdbcab + 10
// cdbc + 14

// aabbaaxybbaabb
// aabbaaxybb + 10
// aaxybb + 20
