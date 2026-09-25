class Solution {
public:

    // Merge two sets using concatenation
    set<string> multiply(set<string> a, set<string> b) {
        set<string> ans;

        for (string x : a) {
            for (string y : b) {
                ans.insert(x + y);
            }
        }

        return ans;
    }

    // Union of two sets
    set<string> add(set<string> a, set<string> b) {
        for (string x : b) {
            a.insert(x);
        }

        return a;
    }

    set<string> solve(string &s, int &i) {

        set<string> ans;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            // Case 1: comma -> union
            if (s[i] == ',') {
                ans = add(ans, current);
                current = {""};
                i++;
            }

            // Case 2: opening brace
            else if (s[i] == '{') {
                i++; // skip '{'

                set<string> inside = solve(s, i);

                i++; // skip '}'

                current = multiply(current, inside);
            }

            // Case 3: normal lowercase letter
            else {
                string temp = "";

                while (i < s.size() && 
                       s[i] >= 'a' && s[i] <= 'z') {
                    temp += s[i];
                    i++;
                }

                set<string> letter = {temp};

                current = multiply(current, letter);
            }
        }

        // Add last part
        ans = add(ans, current);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = solve(expression, i);

        vector<string> ans;

        for (string word : result) {
            ans.push_back(word);
        }

        return ans;
    }
};