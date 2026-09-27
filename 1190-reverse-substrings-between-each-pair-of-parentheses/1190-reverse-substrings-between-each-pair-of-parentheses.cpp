class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        vector<char> ans;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == ')') {

                ans.clear();   // missing

                while(!st.empty() && st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }

                st.pop(); // remove '('

                for(int j = 0; j < ans.size(); j++) {
                    st.push(ans[j]);
                }
            }
            else {
                st.push(s[i]);
            }
        }

        string sta = "";

        // missing: take remaining characters from stack
        while(!st.empty()) {
            sta += st.top();
            st.pop();
        }

        reverse(sta.begin(), sta.end());

        return sta;
    }
};


