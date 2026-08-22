class MinStack {
private:
    vector<int> mystack;
    vector<int> minstack;
public:
    MinStack() = default;
    void push(int val) {

        mystack.push_back(val);
        if(!minstack.empty()) minstack.push_back(min(minstack.back(),val));
        else minstack.push_back(val);
    }
    
    void pop() {
        mystack.pop_back();
        minstack.pop_back();
    }
    
    int top() {
        return mystack.back();
    }
    
    int getMin() {
        return minstack.back();
    }
};
