class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) {
            return false;
        }
        vector<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push_back(s[i]);
            }
            else {
                if (!stk.empty() && ((s[i] == ')' && stk.back() == '(') || (s[i] == ']' && stk.back() == '[') || (s[i] == '}' && stk.back() == '{'))) {
                    stk.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        if (!stk.empty()) return false;
        return true;
    }
};
