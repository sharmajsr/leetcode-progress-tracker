class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size(), ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (operations[i] == "+") {
                int el1 = st.top();
                st.pop();
                int el2 = st.top();
                // st.pop();
                st.push(el1);
                st.push(el1 + el2);
            } else if (operations[i] == "D") {
                int el1 = st.top();
                // st.pop();
                st.push(el1 * 2);
            } else if (operations[i] == "C") {
                st.pop();
            } else {
                st.push(stoi(operations[i]));
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};