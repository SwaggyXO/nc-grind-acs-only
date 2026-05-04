class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (isOpening(s[i])) stk.push_back(s[i]);

            else {
                if (!stk.empty()) {
                    char openingBrace = getOpeningBrace(s[i]);
                    if (stk.back() != openingBrace) return false;
                    stk.pop_back();
                }
                else return false;
            }
        }

        if (!stk.empty()) return false;
        return true;
    }
private:
    bool isOpening(char c) {
        if (c == '(' || c == '[' || c == '{') return true;
        return false;
    }

    char getOpeningBrace(char c) {
        if (c == ')') return '(';
        else if (c == ']') return '[';
        else return '{';
    }
};
