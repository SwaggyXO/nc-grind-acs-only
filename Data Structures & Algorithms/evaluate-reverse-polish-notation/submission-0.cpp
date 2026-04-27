class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> results;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/") {
                int b = results.back(); results.pop_back();
                int a = results.back(); results.pop_back();

                int val;
                if (tokens[i] == "+") val = a + b;
                else if (tokens[i] == "-") val = a - b;
                else if (tokens[i] == "*") val = a * b;
                else val = a / b;

                results.push_back(val);
            }
            else results.push_back(stoi(tokens[i]));
        }
        return results.back();
    }
};
