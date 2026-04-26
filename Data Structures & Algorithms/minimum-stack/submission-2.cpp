class MinStack {
public:
    vector<pair<int, int>> stk;
    MinStack() {
    }
    
    void push(int val) {
        int minVal = stk.empty() ? val : min(stk.back().second, val);
        stk.push_back({val, minVal});
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};
