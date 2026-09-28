class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxsize=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                st.pop();
            }
            else if(s[i]=='('){
                st.push(s[i]);
                // because st.size() returns size_t (unsigned), while maxsize is usually an int.
                maxsize = max(maxsize, (int)st.size());
            }
            
        }
        return maxsize;
    }
};